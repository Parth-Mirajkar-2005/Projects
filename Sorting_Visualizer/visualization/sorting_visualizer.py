import matplotlib
matplotlib.use('TkAgg')
from matplotlib.figure import Figure
import matplotlib.colors
import numpy as np

class SortingVisualizer:
    """A class to create a simple visualization of sorting algorithms using Matplotlib."""
    
    def __init__(self, data, steps, algorithm_name, root, complexities, show_numbers=True):
        """Set up the visualizer with the data, steps, algorithm name, Tkinter root, complexities, and show numbers option.

        Args:
            data (list): The list of numbers to sort.
            steps (list): List of steps from the sorting algorithm.
            algorithm_name (str): Name of the sorting algorithm (e.g., "Bubble Sort").
            root: The Tkinter root window for animation updates.
            complexities (dict): Dictionary containing best_time, worst_time, and space complexities.
            show_numbers (bool): Whether to show numbers on top of bars.
        """
        # Check if data and steps are valid
        if not data or not steps:
            raise ValueError("Data and steps cannot be empty")

        # Validate the first step
        if steps:
            first_step = steps[0]
            if not isinstance(first_step, tuple) or len(first_step) != 2:
                raise ValueError(f"Each step must be a tuple of (array_state, indices). Got: {first_step}")
            array_state, indices = first_step
            if not isinstance(array_state, list) or not isinstance(indices, list):
                raise ValueError(f"Step must contain (list, list). Got: ({type(array_state)}, {type(indices)})")

        # Store the initial data and steps
        self.original_data = data.copy()
        self.data = data.copy()
        self.steps = steps
        self.algorithm_name = algorithm_name
        self.root = root  # Tkinter root for scheduling updates
        self.complexities = complexities  # Store the complexities dictionary
        self.show_numbers = show_numbers  # Store the show_numbers state
        self.current_step = 0
        self.paused = True  # Start paused
        self.speed = 1000  # Default speed in ms (integer)
        self.animation_id = None  # For Tkinter after() method
        self.text_labels = []  # To store the text labels for numbers
        self.canvas = None  # Store the canvas for updates
        self.complexities_text = None  # To store the complexities text object
        
        # Create a gradient of colors for the bars (light to bright)
        self.colors = self._create_gradient_colors(len(data))
        
        # Set up the Matplotlib figure
        self.figure = Figure(figsize=(8, 5), dpi=100)
        self.ax = self.figure.add_subplot(111)
        self._setup_visualization()

    def _create_gradient_colors(self, num_bars):
        """Create a gradient of colors from light to bright based on position.

        Args:
            num_bars (int): Number of bars (length of the data).

        Returns:
            list: List of colors for each bar.
        """
        # Define the lightest and brightest colors (light blue to bright blue)
        light_color = np.array([173, 216, 230]) / 255  # #ADD8E6 (light blue)
        bright_color = np.array([0, 0, 255]) / 255     # #0000FF (bright blue)

        # Create a gradient from light to bright based on position
        colors = []
        for i in range(num_bars):
            # Calculate the fraction (0 to 1) based on position
            fraction = i / (num_bars - 1) if num_bars > 1 else 0
            # Interpolate between light and bright colors
            color = light_color + fraction * (bright_color - light_color)
            colors.append(color)
        print(f"Generated colors: {colors[:5]}...")  # Debug first 5 colors
        return colors

    def _setup_visualization(self):
        """Set up the Matplotlib figure and bars."""
        # Set the title with the current step
        self.ax.set_title(f"{self.algorithm_name} - Step: 0/{len(self.steps)-1}")
        self.ax.set_xticks([])  # Hide x-axis ticks
        self.ax.set_yticks([])  # Hide y-axis ticks
        
        # Create bars with the gradient colors
        num_elements = len(self.data)
        bar_width = min(0.8, 10 / num_elements)  # Adjust width for large datasets
        self.bars = self.ax.bar(
            range(num_elements),
            self.data,
            color=self.colors,
            width=bar_width,
            edgecolor='white'
        )
        
        # Add number labels above each bar (initially hidden if show_numbers is False)
        self.text_labels = []
        for i, bar in enumerate(self.bars):
            height = bar.get_height()
            text = self.ax.text(
                bar.get_x() + bar.get_width() / 2,
                height + 1,
                f"{int(height)}",
                ha='center', va='bottom', fontsize=max(8, 12 - num_elements // 10)
            )
            text.set_visible(self.show_numbers)  # Set visibility based on show_numbers
            self.text_labels.append(text)

        # Initialize the complexities text (hidden initially)
        self.complexities_text = self.ax.text(
            0.02, 0.98,  # Top-left corner (normalized coordinates)
            "",  # Initially empty
            transform=self.ax.transAxes,  # Use axes coordinates (0 to 1)
            fontsize=9,  # Slightly smaller font to fit multiple lines
            verticalalignment='top',
            bbox=dict(facecolor='white', alpha=0.8, edgecolor='black')
        )

    def update_visualization(self):
        """Update the visualization for the current step."""
        print(f"Updating frame: {self.current_step}, Paused: {self.paused}")
        if self.paused:
            print("Animation paused, returning early")
            return
        
        if self.current_step >= len(self.steps):
            print("Reached the end of steps")
            self.paused = True
            return
        
        self._update_bars()
        if self.canvas:
            self.canvas.draw()
            self.canvas.flush_events()
            print("Canvas updated for frame", self.current_step)
        
        # Schedule the next frame (ensure speed is an integer)
        self.current_step += 1
        if not self.paused and self.current_step < len(self.steps):
            self.animation_id = self.root.after(int(self.speed), self.update_visualization)

    def _update_bars(self):
        """Update the heights, colors, and labels of the bars for the current step."""
        # Get the current step data
        try:
            current_data, indices = self.steps[self.current_step]
        except ValueError as e:
            raise ValueError(
                f"Invalid step format at step {self.current_step}. Expected (array_state, indices). Got: {self.steps[self.current_step]}"
            ) from e
        print(f"Step {self.current_step}: Data = {current_data}, Indices = {indices}")
        
        # Find which bars are being swapped
        swapped = set()
        for i, j in indices:  # Now indices only contain swaps
            swapped.add(i)
            swapped.add(j)
        print(f"Swapped indices: {swapped}")
        
        # Check if this is the last step (sorting is complete)
        is_last_step = self.current_step == len(self.steps) - 1
        
        # Update each bar and its label
        for i, (bar, text) in enumerate(zip(self.bars, self.text_labels)):
            # Get the old height before updating
            old_height = bar.get_height()
            new_height = current_data[i]
            bar.set_height(new_height)
            
            # Color the bar: if last step, revert to gradient; otherwise, orange if swapping
            if is_last_step:
                bar.set_color(self.colors[i])  # Revert to original gradient color
            else:
                if i in swapped:
                    bar.set_color('#FF4500')  # Orange for swapping
                else:
                    bar.set_color(self.colors[i])  # Gradient color
            print(f"Bar {i}: Height = {new_height}, Color = {bar.get_facecolor()}")
            
            # Update the number label if the height has changed
            if abs(new_height - old_height) > 0.1:
                text.set_position((bar.get_x() + bar.get_width() / 2, new_height + 1))
                text.set_text(f"{int(new_height)}")
                print(f"Updated text for bar {i}: Position = ({bar.get_x() + bar.get_width() / 2}, {new_height + 1}), Text = {int(new_height)}")
        
        # Update the title with the current step
        self.ax.set_title(f"{self.algorithm_name} - Step: {self.current_step}/{len(self.steps)-1}")

        # Show complexities only on the last step
        if is_last_step:
            complexities_text = (
                f"Best Time: {self.complexities['best_time']}\n"
                f"Worst Time: {self.complexities['worst_time']}\n"
                f"Space: {self.complexities['space']}"
            )
            self.complexities_text.set_text(complexities_text)
        else:
            self.complexities_text.set_text("")  # Hide during animation

    def start_animation(self, canvas, start_frame=0):
        """Start the animation from the specified step.

        Args:
            canvas: The Matplotlib canvas to draw on.
            start_frame (int): The step to start from (default: 0).
        """
        print(f"Starting animation in SortingVisualizer from frame {start_frame}")
        if self.animation_id:
            print("Cancelling existing animation")
            self.root.after_cancel(self.animation_id)
            self.animation_id = None
        
        if not self.steps:
            print("No steps to animate, skipping animation setup")
            return
        
        self.canvas = canvas
        self.current_step = start_frame
        self.update_visualization()

    def toggle_play(self, canvas):
        """Toggle the play/pause state of the animation.

        Args:
            canvas: The Matplotlib canvas to draw on.
        """
        print(f"Toggling play/pause, Current step: {self.current_step}, Paused: {self.paused}")
        if self.current_step >= len(self.steps) - 1:
            self.reset()
        
        self.paused = not self.paused
        if self.paused:
            if self.animation_id:
                self.root.after_cancel(self.animation_id)
                self.animation_id = None
                print("Animation stopped")
        else:
            self.start_animation(canvas, start_frame=self.current_step)
            print("Animation started/resumed")
        canvas.flush_events()

    def next_step(self):
        """Move to the next step manually."""
        if self.current_step < len(self.steps) - 1:
            self.current_step += 1
            self._update_bars()
            if self.canvas:
                self.canvas.draw()

    def prev_step(self):
        """Move to the previous step manually."""
        if self.current_step > 0:
            self.current_step -= 1
            self._update_bars()
            if self.canvas:
                self.canvas.draw()

    def reset(self):
        """Reset the visualization to the starting state."""
        print("Resetting SortingVisualizer")
        self.current_step = 0
        self.paused = True
        if self.animation_id:
            self.root.after_cancel(self.animation_id)
            self.animation_id = None
        self._update_bars()
        if self.canvas:
            self.canvas.draw()

    def set_speed(self, val):
        """Set the animation speed based on the slider value.

        Args:
            val (float): The slider value.
        """
        slider_value = float(val)
        new_speed = 1050 - slider_value  # Invert: 50 -> 1000, 1000 -> 50
        new_speed = max(50, min(1000, new_speed))
        # Ensure speed is an integer for Tkinter's after() method
        new_speed = int(new_speed)
        print(f"Speed slider value: {slider_value}, Calculated interval: {new_speed} ms")
        self.speed = new_speed

    def get_status(self):
        """Get the current status for the UI.

        Returns:
            str: The status message (e.g., "Running | Step: 5/10").
        """
        if self.current_step == len(self.steps) - 1:
            return "Completed!"
        status = "Running" if not self.paused else "Paused"
        return f"{status} | Step: {self.current_step}/{len(self.steps)-1}"

    def toggle_numbers(self, show):
        """Toggle the visibility of numbers on top of bars.

        Args:
            show (bool): Whether to show the numbers.
        """
        self.show_numbers = show
        for text in self.text_labels:
            text.set_visible(show)

    def cleanup(self):
        """Clean up resources when closing the visualizer."""
        print("Cleaning up SortingVisualizer")
        if self.animation_id is not None:
            try:
                self.root.after_cancel(self.animation_id)
                print("Animation stopped successfully")
            except Exception as e:
                print(f"Error stopping animation: {e}")
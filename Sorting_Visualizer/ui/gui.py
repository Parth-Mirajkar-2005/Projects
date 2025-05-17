import tkinter as tk
from tkinter import ttk
import matplotlib
matplotlib.use('TkAgg')
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from visualization.sorting_visualizer import SortingVisualizer

class SortingVisualizerUI(tk.Frame):
    """A Tkinter Frame to manage the UI for the Sorting Visualizer."""

    def __init__(self, parent, data, algorithm, algorithm_name, complexities, show_numbers=True):
        """Initialize the UI with the dataset, algorithm, algorithm name, complexities, and show numbers option.

        Args:
            parent: The parent Tkinter widget.
            data (list): The initial dataset to visualize.
            algorithm (callable): The sorting algorithm function.
            algorithm_name (str): Name of the sorting algorithm.
            complexities (dict): Dictionary containing best_time, worst_time, and space complexities.
            show_numbers (bool): Whether to show numbers on top of bars.
        """
        super().__init__(parent)
        self.parent = parent
        self.data = data
        self.algorithm = algorithm
        self.algorithm_name = algorithm_name
        self.complexities = complexities
        self.show_numbers = show_numbers  # Store the show_numbers state
        
        # Generate steps
        self.steps = self.algorithm(self.data.copy())
        print(f"Generated {len(self.steps)} steps for {self.algorithm_name}")
        
        # Initialize the visualizer with the Tkinter root, complexities, and show_numbers
        self.visualizer = SortingVisualizer(
            self.data,
            self.steps,
            self.algorithm_name,
            self.parent,
            self.complexities,
            show_numbers=self.show_numbers  # Pass the show_numbers state
        )
        
        self.setup_ui()

    def setup_ui(self):
        """Set up the Tkinter UI components."""
        self.configure(padx=10, pady=10)
        
        # Visualization frame
        self.viz_frame = ttk.Frame(self)
        self.viz_frame.pack(fill=tk.BOTH, expand=True)
        
        # Embed matplotlib canvas
        self.canvas = FigureCanvasTkAgg(self.visualizer.figure, master=self.viz_frame)
        self.canvas.draw()
        self.canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)
        self.update()
        
        # Control panel
        self.control_frame = ttk.Frame(self)
        self.control_frame.pack(fill=tk.X, pady=10)
        
        # Control buttons
        self.play_btn = self._create_button("▶ Play", self.toggle_play)
        self.play_btn.pack(side=tk.LEFT, padx=2)
        self._create_button("⏮ Prev", self.prev_step).pack(side=tk.LEFT, padx=2)
        self._create_button("⏭ Next", self.next_step).pack(side=tk.LEFT, padx=2)
        self._create_button("↻ Reset", self.reset).pack(side=tk.LEFT, padx=2)
        
        # Speed control
        ttk.Label(self.control_frame, text="Speed:").pack(side=tk.LEFT, padx=(10, 2))
        self.speed_slider = ttk.Scale(
            self.control_frame,
            from_=100,
            to=50000,
            value=300,
            command=self.update_speed
        )
        self.speed_slider.pack(side=tk.LEFT, fill=tk.X, expand=True, padx=2)
        
        # Status label
        self.status_label = ttk.Label(
            self.control_frame,
            text="Ready | Paused",
            relief=tk.SUNKEN,
            width=30,
            anchor=tk.CENTER
        )
        self.status_label.pack(side=tk.LEFT, padx=5)
        
        self.control_frame.update()
        self.update()

    def _create_button(self, text, command):
        """Helper method to create a button with consistent styling.

        Args:
            text (str): The button text.
            command (callable): The command to execute on button click.

        Returns:
            ttk.Button: The created button.
        """
        return ttk.Button(self.control_frame, text=text, command=command, width=8)

    def toggle_play(self):
        """Toggle the play/pause state."""
        print("Play/Pause button clicked in SortingVisualizerUI")
        self.visualizer.toggle_play(self.canvas)
        print(f"Play button state: {'▶ Play' if self.visualizer.paused else '⏸ Pause'}")
        self.play_btn.config(text="▶ Play" if self.visualizer.paused else "⏸ Pause")
        self.update_status()
        self.canvas.flush_events()
        self.update()

    def next_step(self):
        """Advance one step manually."""
        print("Next button clicked")
        self.visualizer.next_step()
        self.canvas.draw()
        self.update_status()

    def prev_step(self):
        """Go back one step manually."""
        print("Previous button clicked")
        self.visualizer.prev_step()
        self.canvas.draw()
        self.update_status()

    def reset(self):
        """Reset the visualization to the initial state."""
        print("Reset button clicked in SortingVisualizerUI")
        self.visualizer.reset()
        self.play_btn.config(text="▶ Play")
        self.status_label.config(text="Reset | Ready")
        self.canvas.draw()

    def update_speed(self, val):
        """Update the animation speed with throttling.

        Args:
            val (float): The slider value.
        """
        print(f"Updating speed to {val}")
        self.visualizer.set_speed(val)
        self.canvas.flush_events()
        self.after(100)  # Throttle updates to prevent event loop overload

    def update_status(self):
        """Update the status label."""
        self.status_label.config(text=self.visualizer.get_status())

    def toggle_numbers(self, show):
        """Toggle the visibility of numbers on bars.

        Args:
            show (bool): Whether to show the numbers.
        """
        self.visualizer.toggle_numbers(show)
        self.canvas.draw()

    def cleanup(self):
        """Clean up resources."""
        self.visualizer.cleanup()
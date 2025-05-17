import tkinter as tk
from tkinter import ttk, messagebox
import random
from algorithms import sorting_algorithms
from ui.gui import SortingVisualizerUI

class SortingVisualizerApp:
    """Main application class for the Sorting Visualizer."""

    def __init__(self, root):
        """Initialize the application.

        Args:
            root: The Tkinter root window.
        """
        self.root = root
        self.root.title("Sorting Visualizer - Heap Sort")  # Set initial title to match default algorithm
        self.visualizer = None
        # Define complexities for each algorithm (best time, worst time, space)
        self.complexities = {
            # O(n log n) average case
            "Heap Sort": {
                "best_time": "O(n log n)",
                "worst_time": "O(n log n)",
                "space": "O(1)"
            },
            "Merge Sort": {
                "best_time": "O(n log n)",
                "worst_time": "O(n log n)",
                "space": "O(n)"
            },
            "Comb Sort": {
                "best_time": "O(n log n)",
                "worst_time": "O(n²)",
                "space": "O(1)"
            },
            "Quick Sort": {
                "best_time": "O(n log n)",
                "worst_time": "O(n²)",
                "space": "O(log n) average, O(n) worst"
            },
            # O(n^{1.3}) average case
            "Shell Sort": {
                "best_time": "O(n log n)",
                "worst_time": "O(n²)",
                "space": "O(1)"
            },
            # O(n + k) average case
            "Counting Sort": {
                "best_time": "O(n + k)",
                "worst_time": "O(n + k)",
                "space": "O(k)"
            },
            "Bucket Sort": {
                "best_time": "O(n + k)",
                "worst_time": "O(n²)",
                "space": "O(n + k)"
            },
            # O(nk) average case
            "Radix Sort": {
                "best_time": "O(nk)",
                "worst_time": "O(nk)",
                "space": "O(n + k)"
            },
            # O(n²) average case (sorted alphabetically)
            "Bubble Sort": {
                "best_time": "O(n)",
                "worst_time": "O(n²)",
                "space": "O(1)"
            },
            "Cocktail Shaker Sort": {
                "best_time": "O(n)",
                "worst_time": "O(n²)",
                "space": "O(1)"
            },
            "Gnome Sort": {
                "best_time": "O(n)",
                "worst_time": "O(n²)",
                "space": "O(1)"
            },
            "Insertion Sort": {
                "best_time": "O(n)",
                "worst_time": "O(n²)",
                "space": "O(1)"
            },
            "Selection Sort": {
                "best_time": "O(n²)",
                "worst_time": "O(n²)",
                "space": "O(1)"
            },
        }
        self.setup_ui()
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)
        # Start with an initial visualization
        self.start_visualization()

    def setup_ui(self):
        """Set up the main application UI."""
        self.main_frame = ttk.Frame(self.root, padding="10")
        self.main_frame.pack(fill=tk.BOTH, expand=True)
        
        # Control panel
        control_frame = ttk.LabelFrame(self.main_frame, text="Controls", padding="10")
        control_frame.pack(fill=tk.X, pady=5)
        
        self._setup_control_panel(control_frame)
        
        # Visualization area
        self.visualization_frame = ttk.Frame(self.main_frame)
        self.visualization_frame.pack(fill=tk.BOTH, expand=True)

    def _setup_control_panel(self, control_frame):
        """Set up the control panel with algorithm selection, data size slider, custom input, and start button.

        Args:
            control_frame: The frame to add the controls to.
        """
        # Algorithm selection
        ttk.Label(control_frame, text="Algorithm:").grid(row=0, column=0, sticky=tk.W)
        self.algorithm_var = tk.StringVar(value="Heap Sort")
        algorithm_menu = ttk.Combobox(
            control_frame,
            textvariable=self.algorithm_var,
            values=list(sorting_algorithms.keys()),
            state="readonly",
            width=15
        )
        algorithm_menu.grid(row=0, column=1, sticky=tk.W, padx=5)
        algorithm_menu.bind("<<ComboboxSelected>>", lambda _: self.update_window_title())
        
        # Toggle between random data and custom input
        self.use_custom_input = tk.BooleanVar(value=False)
        self.custom_input_check = ttk.Checkbutton(
            control_frame,
            text="Use Custom Input",
            variable=self.use_custom_input,
            command=self.toggle_custom_input
        )
        self.custom_input_check.grid(row=1, column=0, columnspan=2, sticky=tk.W, pady=2)
        
        # Custom input field (initially disabled)
        ttk.Label(control_frame, text="Custom Input (comma-separated):").grid(row=2, column=0, sticky=tk.W)
        self.custom_input_entry = ttk.Entry(control_frame, width=30, state="disabled")
        self.custom_input_entry.grid(row=2, column=1, columnspan=2, sticky=tk.EW, padx=5)
        self.custom_input_entry.insert(0, "5, 3, 8, 1, 9")  # Default example
        
        # Data size slider (for random data)
        ttk.Label(control_frame, text="Data Size (Random):").grid(row=3, column=0, sticky=tk.W)
        self.size_var = tk.IntVar(value=30)
        self.size_slider = ttk.Scale(
            control_frame,
            from_=10,
            to=500,
            variable=self.size_var,
            command=lambda _: self.update_size_label()
        )
        self.size_slider.grid(row=3, column=1, sticky=tk.EW, padx=5)
        self.size_label = ttk.Label(control_frame, text="30 elements")
        self.size_label.grid(row=3, column=2, padx=5)
        
        # Checkbox to show/hide numbers on bars
        self.show_numbers = tk.BooleanVar(value=True)  # Default to showing numbers
        self.show_numbers_check = ttk.Checkbutton(
            control_frame,
            text="Show Numbers on Bars",
            variable=self.show_numbers,
            command=self.toggle_numbers_visibility
        )
        self.show_numbers_check.grid(row=4, column=0, columnspan=2, sticky=tk.W, pady=2)
        
        # Start button
        ttk.Button(
            control_frame,
            text="Start Visualization",
            command=self.start_visualization
        ).grid(row=5, column=0, columnspan=3, pady=5, sticky=tk.EW)

    def toggle_custom_input(self):
        """Enable or disable the custom input field and size slider based on the toggle."""
        if self.use_custom_input.get():
            self.custom_input_entry.config(state="normal")
            self.size_slider.config(state="disabled")
            self.size_label.config(state="disabled")
        else:
            self.custom_input_entry.config(state="disabled")
            self.size_slider.config(state="normal")
            self.size_label.config(state="normal")
        self.update_size_label()

    def toggle_numbers_visibility(self):
        """Toggle the visibility of numbers on bars in the current visualization."""
        if self.visualizer:
            self.visualizer.toggle_numbers(self.show_numbers.get())

    def update_size_label(self, *args):
        """Update the data size label."""
        if self.use_custom_input.get():
            # Count the number of elements in the custom input
            try:
                custom_data = self.parse_custom_input()
                self.size_label.config(text=f"{len(custom_data)} elements")
            except ValueError:
                self.size_label.config(text="Invalid input")
        else:
            self.size_label.config(text=f"{self.size_var.get()} elements")

    def parse_custom_input(self):
        """Parse the custom input into a list of integers.

        Returns:
            list: The parsed list of integers.

        Raises:
            ValueError: If the input is invalid.
        """
        input_text = self.custom_input_entry.get().strip()
        if not input_text:
            raise ValueError("Custom input cannot be empty")
        
        # Split by comma and remove whitespace
        try:
            numbers = [int(num.strip()) for num in input_text.split(",") if num.strip()]
        except ValueError:
            raise ValueError("Custom input must be a comma-separated list of integers (e.g., 5, 3, 8, 1, 9)")
        
        if not numbers:
            raise ValueError("Custom input cannot be empty")
        
        # Check size constraints
        if len(numbers) < 10 or len(numbers) > 500:
            raise ValueError("Custom input size must be between 10 and 500 elements")
        
        # Check for non-negative numbers if using Radix Sort or Counting Sort
        algorithm_name = self.algorithm_var.get()
        if algorithm_name in ["Radix Sort", "Counting Sort"] and any(num < 0 for num in numbers):
            raise ValueError(f"{algorithm_name} requires non-negative integers")
        
        return numbers

    def update_window_title(self):
        """Update the window title based on the selected algorithm."""
        self.root.title(f"Sorting Visualizer - {self.algorithm_var.get()}")

    def start_visualization(self):
        """Start the sorting visualization."""
        # Clear previous visualization
        for widget in self.visualization_frame.winfo_children():
            widget.destroy()
        
        # Get the data based on the input mode
        try:
            if self.use_custom_input.get():
                # Use custom input
                data = self.parse_custom_input()
            else:
                # Use random data
                size = self.size_var.get()
                if size < 10 or size > 500:
                    messagebox.showerror("Error", "Dataset size must be between 10 and 500")
                    return
                data = [random.randint(10, 500) for _ in range(size)]
        except ValueError as e:
            messagebox.showerror("Error", str(e))
            return
        
        # Get the selected algorithm
        algorithm_name = self.algorithm_var.get()
        if algorithm_name not in sorting_algorithms:
            messagebox.showerror("Error", f"Algorithm '{algorithm_name}' not found")
            return
        algorithm = sorting_algorithms[algorithm_name]
        
        # Get the complexities for the selected algorithm
        complexities = self.complexities.get(algorithm_name, {
            "best_time": "Unknown",
            "worst_time": "Unknown",
            "space": "Unknown"
        })
        
        self.visualizer = SortingVisualizerUI(
            self.visualization_frame,
            data,
            algorithm,
            algorithm_name,
            complexities,
            show_numbers=self.show_numbers.get()  # Pass the show_numbers state
        )
        self.visualizer.pack(fill=tk.BOTH, expand=True)
        self.update_window_title()

    def on_close(self):
        """Clean up when the main window closes."""
        if self.visualizer:
            try:
                self.visualizer.cleanup()
            except Exception as e:
                print(f"Error during cleanup: {e}")
        self.root.destroy()

if __name__ == "__main__":
    root = tk.Tk()
    root.geometry("800x600")
    app = SortingVisualizerApp(root)
    root.mainloop()
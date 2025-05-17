from .bubble_sort import bubble_sort
from .selection_sort import selection_sort
from .insertion_sort import insertion_sort
from .merge_sort import merge_sort
from .quick_sort import quick_sort
from .heap_sort import heap_sort
from .counting_sort import counting_sort
from .radix_sort import radix_sort
from .bucket_sort import bucket_sort
from .shell_sort import shell_sort
from .cocktail_shaker_sort import cocktail_shaker_sort
from .gnome_sort import gnome_sort
from .comb_sort import comb_sort

sorting_algorithms = {
    # O(n log n) average case
    "Heap Sort": heap_sort,           # O(n log n) worst
    "Merge Sort": merge_sort,         # O(n log n) worst
    "Comb Sort": comb_sort,           # O(n²) worst
    "Quick Sort": quick_sort,         # O(n²) worst
    # O(n^{1.3}) average case
    "Shell Sort": shell_sort,         # O(n²) worst
    # O(n + k) average case
    "Counting Sort": counting_sort,   # O(n + k) worst
    "Bucket Sort": bucket_sort,       # O(n²) worst
    # O(nk) average case
    "Radix Sort": radix_sort,         # O(nk) worst
    # O(n²) average case (sorted alphabetically)
    "Bubble Sort": bubble_sort,
    "Cocktail Shaker Sort": cocktail_shaker_sort,
    "Gnome Sort": gnome_sort,
    "Insertion Sort": insertion_sort,
    "Selection Sort": selection_sort,
}

__all__ = ['sorting_algorithms']
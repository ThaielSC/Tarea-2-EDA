import matplotlib.pyplot as plt
import csv
import os
from collections import defaultdict

def plot_results():
    results_dir = "results"
    csv_path = os.path.join(results_dir, "results.csv")
    plot_path = os.path.join(results_dir, "benchmark_plot.svg")

    # Create results directory if it doesn't exist
    os.makedirs(results_dir, exist_ok=True)

    results = defaultdict(lambda: {'sizes': [], 'times': []})

    try:
        with open(csv_path, 'r') as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                try:
                    algorithm = row['Algorithm']
                    size = int(row['Size'])
                    time = float(row['Time_ms'])
                    results[algorithm]['sizes'].append(size)
                    results[algorithm]['times'].append(time)
                except (ValueError, KeyError):
                    # Skip rows that cause errors (like extra headers)
                    continue
    except FileNotFoundError:
        print(f"Error: {csv_path} not found.")
        print("Please run the benchmark first to generate the results file.")
        return
    except (KeyError, ValueError) as e:
        print(f"Error processing CSV file: {e}")
        print("Ensure the CSV has columns: Algorithm,Size,Time_ms")
        return

    # --- Vintage Newspaper Theme --- 
    plt.rcParams['font.family'] = 'serif' # Use a serif font
    fig, ax = plt.subplots(figsize=(12, 8))
    background_color = '#FFF' # A warm, antique white
    text_color = '#2A2A2A' # A warm, brownish-gray for a softer, more integrated look
    grid_color = '#DDDDDD' # A very light grey for subtle grid lines

    fig.patch.set_facecolor(background_color)
    ax.set_facecolor(background_color)

    # Use the exact color palette provided by the user
    color_map = {
        'Radix Sort': '#6FA4AF',    # Teal/Aqua
        'Quick Sort': '#B8C4A9',    # Sage Green
        'Merge Sort': '#D97D55',    # Terracotta/Orange
        'Counting Sort': '#A48A6F'  # A complementary brownish tone if needed
    }
    default_color = text_color # Default to text color if algorithm not in map

    for algorithm, data in results.items():
        # Aggregate results by size (e.g., calculate average time)
        aggregated_data = defaultdict(list)
        for size, time in zip(data['sizes'], data['times']):
            aggregated_data[size].append(time)
        
        avg_sizes = sorted(aggregated_data.keys())
        avg_times = [sum(aggregated_data[size]) / len(aggregated_data[size]) for size in avg_sizes]

        # Get the color from the map or use the default
        plot_color = color_map.get(algorithm, default_color)

        ax.plot(avg_sizes, avg_times, marker='o', markersize=5, linestyle='-', label=algorithm, color=plot_color, linewidth=1.5)

    # --- Style Fonts, Titles, and Labels ---
    # ax.set_title('Análisis de Rendimiento de Algoritmos de Ordenamiento', color=text_color, fontsize=20, fontweight='bold')
    ax.set_xlabel('Tamaño del Conjunto de Datos (N)', color=text_color, fontsize=20)
    ax.set_ylabel('Tiempo de Ejecución Promedio (ms)', color=text_color, fontsize=20)

    # --- Style Legend, Grid, and Spines ---
    legend = ax.legend(frameon=True, shadow=True, fontsize=20)
    legend.get_frame().set_facecolor(background_color)
    legend.get_frame().set_edgecolor(grid_color)
    for text in legend.get_texts():
        text.set_color(text_color)

    ax.grid(True, which="both", linestyle=":", linewidth=0.6, color=grid_color)
    ax.tick_params(axis='x', colors=text_color, labelsize=18)
    ax.tick_params(axis='y', colors=text_color, labelsize=18)

    # Remove top and right spines for a cleaner look
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    ax.spines['left'].set_color(text_color)
    ax.spines['bottom'].set_color(text_color)

    ax.set_xscale('log')
    ax.set_yscale('log')
    fig.tight_layout()

    plt.savefig(plot_path, dpi=500) # Increase DPI for better print quality
    print(f"Gráfico guardado como '{plot_path}'")

if __name__ == '__main__':
    plot_results()

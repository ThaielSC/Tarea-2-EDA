import matplotlib.pyplot as plt
import csv
import os
from collections import defaultdict

def plot_results():
    results_dir = "results"
    csv_path = os.path.join(results_dir, "results.csv")
    plot_path = os.path.join(results_dir, "benchmark_plot.png")

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

    plt.figure(figsize=(12, 8))

    for algorithm, data in results.items():
        # Aggregate results by size (e.g., calculate average time)
        aggregated_data = defaultdict(list)
        for size, time in zip(data['sizes'], data['times']):
            aggregated_data[size].append(time)
        
        avg_sizes = sorted(aggregated_data.keys())
        avg_times = [sum(aggregated_data[size]) / len(aggregated_data[size]) for size in avg_sizes]

        plt.plot(avg_sizes, avg_times, marker='o', linestyle='-', label=algorithm)

    plt.title('Análisis de Rendimiento de Algoritmos de Ordenamiento')
    plt.xlabel('Tamaño del Conjunto de Datos (N)')
    plt.ylabel('Tiempo de Ejecución Promedio (ms)')
    plt.legend()
    plt.grid(True, which="both", ls="--")
    plt.xscale('log')
    plt.yscale('log')
    plt.tight_layout()

    plt.savefig(plot_path)
    print(f"Gráfico guardado como '{plot_path}'")

if __name__ == '__main__':
    plot_results()

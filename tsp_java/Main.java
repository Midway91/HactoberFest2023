package tsp_java;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

class City {
    int x, y;

    public City(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public double distanceTo(City other) {
        int dx = this.x - other.x;
        int dy = this.y - other.y;
        return Math.sqrt(dx * dx + dy * dy);
    }
}

class Route {
    List<City> cities;

    public Route(List<City> cities) {
        this.cities = new ArrayList<>(cities);
        Collections.shuffle(this.cities);
    }

    public double calculateDistance() {
        double totalDistance = 0;
        for (int i = 0; i < cities.size() - 1; i++) {
            totalDistance += cities.get(i).distanceTo(cities.get(i + 1));
        }
        totalDistance += cities.get(cities.size() - 1).distanceTo(cities.get(0));
        return totalDistance;
    }
}

class GeneticAlgorithm {
    List<City> cities;
    int populationSize;

    public GeneticAlgorithm(List<City> cities, int populationSize) {
        this.cities = cities;
        this.populationSize = populationSize;
    }

    public Route findShortestRoute(int generations) {
        List<Route> population = new ArrayList<>();
        for (int i = 0; i < populationSize; i++) {
            population.add(new Route(cities));
        }

        for (int generation = 0; generation < generations; generation++) {
            population.sort((r1, r2) -> Double.compare(r1.calculateDistance(), r2.calculateDistance()));

            List<Route> newPopulation = new ArrayList<>();
            for (int i = 0; i < populationSize / 2; i++) {
                Route parent1 = selectParent(population);
                Route parent2 = selectParent(population);
                Route child = crossover(parent1, parent2);
                mutate(child);
                newPopulation.add(child);
            }
            population = newPopulation;
        }

        return Collections.min(population, (r1, r2) -> Double.compare(r1.calculateDistance(), r2.calculateDistance()));
    }

    private Route selectParent(List<Route> population) {
        Random random = new Random();
        int index = random.nextInt(population.size());
        return population.get(index);
    }

    private Route crossover(Route parent1, Route parent2) {
        int size = parent1.cities.size();
        int start = (int) (Math.random() * size);
        int end = (int) (Math.random() * size);

        if (start > end) {
            int temp = start;
            start = end;
            end = temp;
        }

        List<City> childCities = new ArrayList<>();
        for (int i = start; i < end; i++) {
            childCities.add(parent1.cities.get(i));
        }

        for (City city : parent2.cities) {
            if (!childCities.contains(city)) {
                childCities.add(city);
            }
        }

        return new Route(childCities);
    }

    private void mutate(Route route) {
        Random random = new Random();
        if (random.nextDouble() < 0.02) {
            int index1 = random.nextInt(route.cities.size());
            int index2 = random.nextInt(route.cities.size());
            Collections.swap(route.cities, index1, index2);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        List<City> cities = new ArrayList<>();
        cities.add(new City(0, 0));
        cities.add(new City(1, 2));
        cities.add(new City(2, 4));
        cities.add(new City(3, 1));
        cities.add(new City(4, 3));

        int populationSize = 100;
        int generations = 1000;

        GeneticAlgorithm ga = new GeneticAlgorithm(cities, populationSize);
        Route shortestRoute = ga.findShortestRoute(generations);

        System.out.println("Shortest Route: " + shortestRoute.cities);
        System.out.println("Shortest Distance: " + shortestRoute.calculateDistance());
    }
}

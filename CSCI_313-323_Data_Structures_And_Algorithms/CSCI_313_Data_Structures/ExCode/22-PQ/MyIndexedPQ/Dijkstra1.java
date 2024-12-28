import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;

public class Dijkstra1 {
    private static void printPath(String u, Map<String, String> pred){
        System.out.print(" [");
        while (u != null){
            System.out.printf("%s", u);
            u = pred.get(u);
            if (u == null) System.out.println("]");
            else System.out.print("->");
        } // end-while
    } // end-printPath

    public static void main(String[] args){
        record Edge(String target, int weight){}

        String[] cities = {"A", "B", "C", "D", "E", "F", "G"};

        // Graph: Adjacency list representation
        Map<String, List<Edge>> G = new HashMap<>();
        for (var city: cities)
            G.put(city, new ArrayList<>());

        // Add edges
        G.get("A").add(new Edge("B", 6));  // (A->B, 6)
        G.get("A").add(new Edge("C", 3));  // (A->C, 3)
        G.get("A").add(new Edge("D", 5));  // (A->D, 5)

        G.get("B").add(new Edge("E", 2));  // (B->E, 2)

        G.get("C").add(new Edge("B", 2));  // (C->B, 2)
        G.get("C").add(new Edge("E", 5));  // (C->E, 5)
        G.get("C").add(new Edge("F", 4));  // (C->F, 4)
        G.get("C").add(new Edge("D", 1));  // (C->D, 1)

        G.get("D").add(new Edge("F", 1));  // (D->F, 1)

        G.get("E").add(new Edge("F", 1));  // (E->F, 1)
        G.get("E").add(new Edge("G", 4));  // (E->G, 4)

        G.get("F").add(new Edge("G", 8));  // (F->G, 8)

        // Run Dijksra's Shortest Path algorithm
        Map<String, Integer> d = new HashMap<>();

        enum Color {WHITE, BLACK};
        Map<String, Color> color = new HashMap<>();

        Map<String, String> pred = new HashMap<>();

        // Indexed PQ to store (vertex, cost) pairs
        MyIndexedPQ<String, Integer> pq = new MyIndexedHeapPQ<>();

        // Starting node
        d.put("A", 0);
        pred.put("A", null);
        color.put("A", Color.WHITE);
        pq.push("A", 0);

        for (int i=1; i<cities.length; i++){
            color.put(cities[i], Color.WHITE);
            d.put(cities[i], Integer.MAX_VALUE);
            pq.push(cities[i], d.get(cities[i]));
        } // end-for

        while (!pq.isEmpty()){
            var u = pq.top().getKey();
            pq.pop();

            for (var edge: G.get(u)){
                // Relax (u->v)
                String v = edge.target();
                if (color.get(v) == Color.BLACK) continue;

                if (d.get(u) + edge.weight() < d.get(v)){
                    // We have a shorter path to v
                    d.put(v, d.get(u) + edge.weight());
                    pred.put(v, u);
                    pq.update(v, d.get(v));  // decreaseKey
                } // end-if
            } // end-for

            color.put(u, Color.BLACK);
        } // end-while

        for (int i=1; i<cities.length; i++){
            System.out.printf("Distance[A->%s]: %2d. Shortest Path: ", cities[i], d.get(cities[i]));
            printPath(cities[i], pred);
        } // end-for
    } // end-main
} // end-Dijksra1

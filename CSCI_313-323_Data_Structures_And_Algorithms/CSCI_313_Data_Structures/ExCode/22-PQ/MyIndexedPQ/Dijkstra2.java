import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;

class KeyMapper<K>{
    List<K> keys = new ArrayList<>();
    Map<K, Integer> map = new HashMap<>();

    public int size(){return keys.size();}

    public int add(K key){
        if (map.containsKey(key)) return map.get(key);
        keys.add(key);
        map.put(key, keys.size()-1);
        return keys.size()-1;
    } // end-add

    public int index(K key){
        if (map.containsKey(key)) return map.get(key);
        throw new IllegalArgumentException("index: key " + key + " not found!");
    } // end-index

    public K key(int index){
        if (index < 0 || index >= keys.size())
            throw new IllegalArgumentException("key: index " + index + " out of range!");
        return keys.get(index);
    } // end-key
} // end-KeyMapper

public class Dijkstra2 {
    private static void printPath(int u, int[] pred, KeyMapper<String> keyMapper){
        System.out.print(" [");
        while (u != -1){
            System.out.printf("%s", keyMapper.key(u));
            u = pred[u];
            if (u == -1) System.out.println("]");
            else System.out.print("->");
        } // end-while
    } // end-printPath

    @SuppressWarnings("unchecked")
    public static void main(String[] args){
        KeyMapper<String> keyMapper = new KeyMapper<>();

        String[] cities = {"A", "B", "C", "D", "E", "F", "G"};
        for (var city: cities) keyMapper.add(city);

        record Edge(int target, int weight){}

        int numVertices = cities.length;
        List<Edge>[] G = new List[numVertices];

        for (int i=0; i<numVertices; i++)
            G[i] = new ArrayList<>();

        // Add edges
        G[keyMapper.index("A")].add(new Edge(keyMapper.index("B"), 6));  // (A->B, 6)
        G[keyMapper.index("A")].add(new Edge(keyMapper.index("C"), 3));  // (A->C, 3)
        G[keyMapper.index("A")].add(new Edge(keyMapper.index("D"), 5));  // (A->D, 5)

        G[keyMapper.index("B")].add(new Edge(keyMapper.index("E"), 2));  // (B->E, 2)

        G[keyMapper.index("C")].add(new Edge(keyMapper.index("B"), 2));  // (C->B, 2)
        G[keyMapper.index("C")].add(new Edge(keyMapper.index("E"), 5));  // (C->E, 5)
        G[keyMapper.index("C")].add(new Edge(keyMapper.index("F"), 4));  // (C->F, 4)
        G[keyMapper.index("C")].add(new Edge(keyMapper.index("D"), 1));  // (C->D, 1)

        G[keyMapper.index("D")].add(new Edge(keyMapper.index("F"), 1));  // (D->F, 1)

        G[keyMapper.index("E")].add(new Edge(keyMapper.index("F"), 1));  // (E->F, 1)
        G[keyMapper.index("E")].add(new Edge(keyMapper.index("G"), 4));  // (E->G, 4)

        G[keyMapper.index("F")].add(new Edge(keyMapper.index("G"), 8));  // (F->G, 8)

        // Run Dijksra's Shortest Path algorithm
        int[] d = new int[numVertices];

        enum Color {WHITE, BLACK};
        Color[] color = new Color[numVertices];

        int[] pred = new int[numVertices];

        // Indexed PQ to store (vertex, cost) pairs
        MyIndexedPQWithIntegerKeys<Integer> pq = new MyIndexedPQWithIntegerKeys<>(numVertices);

        // Starting node        
        d[0] = 0;
        pred[0] = -1;
        color[0] = Color.WHITE;
        pq.push(0, 0);

        for (int i=1; i<numVertices; i++){
            color[i] = Color.WHITE;
            d[i] = Integer.MAX_VALUE;
            pq.push(i, d[i]);
        } // end-for

        while (!pq.isEmpty()){
            var u = pq.top().getKey();
            pq.pop();

            for (var edge: G[u]){
                // Relax (u->v)
                int v = edge.target();
                if (color[v] == Color.BLACK) continue;

                if (d[u] + edge.weight() < d[v]){
                    // We have a shorter path to v
                    d[v] = d[u] + edge.weight();
                    pred[v] = u;
                    pq.update(v, d[v]);  // decreaseKey
                } // end-if
            } // end-for

            color[u] = Color.BLACK;
        } // end-while

        for (int i=1; i<numVertices; i++){
            System.out.printf("Distance[A->%s]: %2d. Shortest Path: ", keyMapper.key(i), d[i]);
            printPath(i, pred, keyMapper);
        } // end-for
    } // end-main
} // end-Dijksra2

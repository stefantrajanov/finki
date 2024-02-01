import javax.swing.plaf.IconUIResource;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.Entry;

//class AdjacencyListGraph<T> {
//    private Map<T, Set<T>> adjacencyList;
//
//    public AdjacencyListGraph() {
//        this.adjacencyList = new HashMap<>();
//    }
//
//    // Add a vertex to the graph
//    public void addVertex(T vertex) {
//        if (!adjacencyList.containsKey(vertex)) {
//            adjacencyList.put(vertex, new HashSet<>());
//        }
//    }
//
//    // Remove a vertex from the graph
//    public void removeVertex(T vertex) {
//        // Remove the vertex from all adjacency lists
//        for (Set<T> neighbors : adjacencyList.values()) {
//            neighbors.remove(vertex);
//        }
//        // Remove the vertex's own entry in the adjacency list
//        adjacencyList.remove(vertex);
//    }
//
//    // Add an edge to the graph
//    public void addEdge(T source, T destination) {
//        addVertex(source);
//        addVertex(destination);
//
//        adjacencyList.get(source).add(destination);
//        adjacencyList.get(destination).add(source); // for undirected graph
//    }
//
//    // Remove an edge from the graph
//    public void removeEdge(T source, T destination) {
//        if (adjacencyList.containsKey(source)) {
//            adjacencyList.get(source).remove(destination);
//        }
//        if (adjacencyList.containsKey(destination)) {
//            adjacencyList.get(destination).remove(source); // for undirected graph
//        }
//    }
//
//    // Get all neighbors of a vertex
//    public Set<T> getNeighbors(T vertex) {
//        return adjacencyList.getOrDefault(vertex, new HashSet<>());
//    }
//
//    public void DFS(T startVertex) {
//        Set<T> visited = new HashSet<>();
//        DFSUtil(startVertex, visited);
//    }
//
//    private void DFSUtil(T vertex, Set<T> visited) {
//        // Mark the current node as visited and print it
//        visited.add(vertex);
//        System.out.print(vertex + " ");
//
//        // Recur for all the vertices adjacent to this vertex
//        for (T neighbor : getNeighbors(vertex)) {
//            if (!visited.contains(neighbor)) {
//                DFSUtil(neighbor, visited);
//            }
//        }
//    }
//
//
//    public void DFSNonRecursive(T startVertex) {
//        Set<T> visited = new HashSet<>();
//        Stack<T> stack = new Stack<>();
//
//        stack.push(startVertex);
//        while (!stack.isEmpty()) {
//            T vertex = stack.pop();
//            if (!visited.contains(vertex)) {
//                visited.add(vertex);
//                System.out.print(vertex + " ");
//                for (T neighbor : getNeighbors(vertex)) {
//                    if (!visited.contains(neighbor)) {
//                        stack.push(neighbor);
//                    }
//                }
//            }
//        }
//    }
//
//    public void BFS(T startVertex) {
//        Set<T> visited = new HashSet<>();
//        Queue<T> queue = new LinkedList<>();
//
//        visited.add(startVertex);
//        queue.add(startVertex);
//
//        while (!queue.isEmpty()) {
//            T vertex = queue.poll();
//            System.out.print(vertex + " ");
//
//            for (T neighbor : getNeighbors(vertex)) {
//                if (!visited.contains(neighbor)) {
//                    visited.add(neighbor);
//                    queue.add(neighbor);
//                }
//            }
//        }
//    }
//
//    public void findPath(T startVertex, T endVertex) {
//        Set<T> visited = new HashSet<>();
//        Stack<T> invertedPath = new Stack<>();
//        visited.add(startVertex);
//        invertedPath.push(startVertex);
//
//        while(!invertedPath.isEmpty() && !invertedPath.peek().equals(endVertex)) {
//            T currentVertex = invertedPath.peek();
//            T tmp = currentVertex;
//
//            for(T vertex : getNeighbors(currentVertex)) {
//                tmp = vertex;
//                if(!visited.contains(vertex)) {
//                    break;
//                }
//            }
//
//            if(!visited.contains(tmp)) {
//                visited.add(tmp);
//                invertedPath.push(tmp);
//            }
//            else {
//                invertedPath.pop();
//            }
//        }
//
//        Stack<T> path = new Stack<>();
//        while(!invertedPath.isEmpty()) {
//            path.push(invertedPath.pop());
//        }
//        while(!path.isEmpty()) {
//            System.out.println(path.pop());
//        }
//    }
//
//    @Override
//    public String toString() {
//        String ret = new String();
//        for (Entry<T, Set<T>> vertex : adjacencyList.entrySet())
//            ret += vertex.getKey() + ": " + vertex.getValue() + "\n";
//        return ret;
//    }
//
//
//
//}
public class Graph {
    public static void main(String[] args) throws IOException {
        AdjacencyListGraph<Integer> graph = new AdjacencyListGraph<>();
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());

        for (int i = 0; i < n; i++) {
            String input = reader.readLine();
            if (input.compareTo("CREATE") == 0){
                continue;
            }
            String[] commands = input.split(" ");

            if (commands[0].compareTo("ADJACENT") == 0){
                Set<Integer> neighbors = graph.getNeighbors(Integer.parseInt(commands[1]));
                if (neighbors.contains(Integer.parseInt(commands[2]))) {
                    System.out.println("true");
                } else {
                    System.out.println("false");
                }
                continue;
            }

            switch (commands[0]){
                case "ADDEDGE":
                    graph.addEdge(Integer.parseInt(commands[1]), Integer.parseInt(commands[2]));
                    break;
                case "DELETEEDGE":
                    graph.removeEdge(Integer.parseInt(commands[1]), Integer.parseInt(commands[2]));
                    break;
                case "PRINTGRAPH":
                    System.out.println(graph);
                    break;
                default:
                    break;
            }
        }
    }
}

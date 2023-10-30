import java.util.*;
public class UltiGraph {
    static class edge{
        int src;
        int des;
        edge(int src,int des){
            this.src=src;
            this.des=des;
        }
    }
    public static void createGraph(ArrayList<edge> graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<>();
        }
        graph[0].add(new edge(0,1));
        graph[0].add(new edge(0,2));
        graph[1].add(new edge(1,3));
        graph[2].add(new edge(2,4));
        graph[3].add(new edge(3,4));
        graph[3].add(new edge(3,5));
        graph[4].add(new edge(4,3));
        graph[4].add(new edge(4,5));
        graph[5].add(new edge(5,6));
    }
    public static void bfs(ArrayList<edge> graph[],boolean []vis,int start){
        Queue <Integer>q=new LinkedList<>();
        q.add(start);
        while(!q.isEmpty()){
            int curr=q.poll();
            if(!vis[curr]){
                vis[curr]=true;
                System.out.print(curr+" ");
                for(int i=0;i<graph[curr].size();i++){
                    edge e=graph[curr].get(i);
                    q.add(e.des);
                }
            }
        }
    }
    public static void main(String[] args) {
        ArrayList<edge> graph[]=new ArrayList[7];
        boolean vis[]=new boolean[7];
        createGraph(graph);
        String s="";
        for(int i=0;i<vis.length;i++) {
            if (!vis[i]) {
                bfs(graph,vis,i);
            }
        }
    }
}

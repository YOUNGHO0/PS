import java.util.*;

public class Main{

    int[] parent;
    public boolean union(int e1, int e2){

        int p1 = find(e1);
        int p2 = find(e2);
        if (p1 != p2){
            parent[p2] = p1;
            return true;
        }
        else{
            return false;
        }
    }

    public int find(int e){

        if(e == parent[e]) return e;
        else{
             return parent[e] = find(parent[e]);
        }
    }
    
    public class Node{

        int from;
        int dest;
        int value;

        public Node(int from,int dest, int value){
            this.from = from;
            this.dest = dest;
            this.value = value;
        }
    }
    public void solve(){

        Scanner scanner = new Scanner(System.in);

        int vertex = scanner.nextInt();
        int edge = scanner.nextInt();
        parent = new int[vertex+1];
        for(int i =0; i<parent.length; i++)parent[i] = i;
        List<Node> list = new ArrayList<>();

        for(int i =0; i<edge; i++){

            int from = scanner.nextInt();
            int to = scanner.nextInt();
            int value = scanner.nextInt();
            list.add(new Node(from,to,value));
        }

        Collections.sort(list,(e1,e2)-> e1.value - e2.value);

        int total = 0;
        for(Node n :list){
            if(union(n.from, n.dest)){
                total += n.value;
            }
        }
        System.out.println(total);

        

    }

    public static void main(String [] args){

      Main main = new Main();
      main.solve();
    }
}
import java.util.*;
public class Main{

    Map<Character,Integer> map = new HashMap<>();
    int answer = Integer.MIN_VALUE;
    int []visited = new int[10];
    public void dfs(List<Character> clist, List<String> list, int depth){
        
        if(depth == clist.size()){

            
            int ans = 0;
            for(String str : list){
                int total = 0;
                for(int i =0; i<str.length(); i++){
                    total*= 10;
                    int num = map.get(str.charAt(i));
                    total += num;
                }
                ans += total;
            }
            answer = Math.max(answer,ans);

        }
        else{
            for(int i =0; i<=9; i++){
            if(map.containsValue(i)) continue;
            map.put(clist.get(depth),i);
            dfs(clist,list,depth+1);
            map.remove(clist.get(depth));
        }
        }
        

    }
    public void solve(){

        Set<Character> set = new HashSet<>();

        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        List<String> list = new ArrayList<>();
        for(int i =0; i<num; i++){
            String s = scanner.next();

            for(char c : s.toCharArray()){

                set.add(c);
            }
            list.add(s);
        }

        List<Character> clist = new ArrayList<>(set);

        dfs(clist,list,0);
        System.out.println(answer);

    }

    public static void main(String[] args){

        Main main = new Main();
        main.solve();
        
    }
}
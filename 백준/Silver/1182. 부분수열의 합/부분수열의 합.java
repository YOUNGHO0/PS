import java.util.*;
public class Main
{ 
	int count =0;
	public void combi(int[] arr,int depth, int targetDepth,int pos, int sum, int targetSum){
		
		if(depth == targetDepth){
			if(sum == targetSum){
				count++;
			} 
			
		}
		else{
			if(pos>= arr.length) return;
			combi(arr,depth,targetDepth,pos+1,sum,targetSum);
			combi(arr,depth+1,targetDepth,pos+1,sum+arr[pos],targetSum);
			 
		}
	}


	public void solution(int n, int s ,int[]arr){
		

		for(int i =1; i<=n; i++){
			combi(arr,0,i,0,0,s);
		}
		System.out.println(count);
		

	}

	public static void main(String[] args){
		Scanner scanner  = new Scanner(System.in);
		
		int n = scanner.nextInt();
		int s = scanner.nextInt();
		int[] arr = new int[n];
		
		for(int i =0; i<n; i++){
			arr[i] = scanner.nextInt();
		}

		Main main = new Main();
		main.solution(n,s,arr);
	}
}
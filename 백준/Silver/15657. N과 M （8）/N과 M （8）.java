import java.util.*;
import java.io.*;
public class Main {
	static ArrayList<Integer> list = new ArrayList<>();
	static int N, M;
	static int[] visited = {0, 0, 0, 0, 0, 0 ,0, 0};
	
	static void dfs(int cnt, int pos) {
		// 탈출
		if (cnt == M) {
			for (int j=0; j<N; j++) {
				for (int t=0; t<visited[j]; t++)
					System.out.print(list.get(j)+ " ");
			}
			System.out.println();
			return;
		}
		// 탐색
		for (int i=pos; i<N; i++) {			
				visited[i]++;
				dfs(cnt+1, i);
				visited[i]--;			
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// N개의 자연수 중에서 M개를 고른다.
		N = sc.nextInt();
		M = sc.nextInt();
		
		for (int i=0; i<N; i++) {
			list.add(sc.nextInt());
		}
		Collections.sort(list);
		
		for (int i=0; i<N; i++) {
			visited[i]++;
			dfs(1,i);
			visited[i]--;			
		}
	}

}

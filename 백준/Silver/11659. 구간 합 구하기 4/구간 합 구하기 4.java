import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		int []arr = new int[N+1];
		
		arr[0] = 0;
		for (int i=1; i<=N; i++) {
			arr[i] = sc.nextInt() + arr[i-1];
		}
				
		for (int i=0; i<M; i++) {
			int start = sc.nextInt();
			int dest = sc.nextInt();			
						
			System.out.println(arr[dest] - arr[start-1]);
		}
	}

}

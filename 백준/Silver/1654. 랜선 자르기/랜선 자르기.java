import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// K개의 랜선, N개의 필요한 랜선
		int K = sc.nextInt();
		int N = sc.nextInt();
		
		int[] arr = new int[K];
		
		long max = 0;
		
		for (int i=0; i<K; i++) {
			arr[i] = sc.nextInt();
			if (max < arr[i]) {
				max = arr[i];
			}
		}
		max++;
		long min = 0;
		long mid = 0;
		
		while (min < max) {
			mid = (max + min) / 2;
			
			long cnt = 0;
			
			for (int i=0; i<arr.length; i++) {
				cnt += arr[i]/mid;
			}
			
			if (cnt < N)
				max = mid;
			else {
				min = mid + 1;
			}
		}
		
		System.out.println(min-1);
	}

}

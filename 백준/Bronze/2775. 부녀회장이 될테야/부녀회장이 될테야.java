import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int test_case = sc.nextInt();
		int [][] arr = new int[15][15];
		// 0층 초기화, 1호부터 있다고 생각한다.
		for (int i=0; i<=14; i++) {
			arr[0][i] = i;
			arr[i][1] = 1;
		}
		
		for (int i=1; i<=14; i++) {
			for (int j=2; j<=14; j++) {
				arr[i][j] = arr[i-1][j] + arr[i][j-1];
			}
		}
		
		for (int t=0; t<test_case; t++) {
			int k = sc.nextInt();
			int n = sc.nextInt();
			
			System.out.println(arr[k][n]);
			
		}
	}

}

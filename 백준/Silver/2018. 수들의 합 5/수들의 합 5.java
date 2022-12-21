import java.util.*;
import java.io.*;
public class Main {		
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int left = 1;		
		int sum = 0;
		int cnt = 0;
		
		while (left <= N)
		{
			for (int i=left; i<=N; i++)
			{
				sum += i;
				if (sum == N)
				{
					cnt++;
					break;
				}
				else if (sum > N)
				{
					break;
				}
			}
			left++;
			sum = 0;
		}
		
		System.out.println(cnt);
		
		
	}
}

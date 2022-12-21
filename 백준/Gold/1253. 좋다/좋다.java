import java.util.*;
import java.io.*;
public class Main {		
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long arr[] = new long[N];
		
		for (int i=0; i<N; i++)
		{
			arr[i] = sc.nextLong();
		}
		Arrays.sort(arr);
		
		int cnt=0;
		for (int i=0; i<N; i++)
		{
			int left=0;
			int right = N-1;
			
			while (left < right)
			{
				if (left == i)
				{
					left++;
					continue;
				}
				else if (right == i)
				{
					right--;
					continue;
				}
				
				if (arr[left] + arr[right] == arr[i])
				{
					cnt++;
					break;
				}
				else if (arr[left] + arr[right] < arr[i])
				{
					left++;
				}
				else if (arr[left] + arr[right] > arr[i])
				{
					right--;
				}
			}
		}
		System.out.println(cnt);
	}
}

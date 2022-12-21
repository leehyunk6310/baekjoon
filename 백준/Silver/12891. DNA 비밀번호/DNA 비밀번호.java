import java.util.*;
import java.io.*;
public class Main {		
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int S = sc.nextInt();
		int P = sc.nextInt();
		String s = sc.next();
		int a = sc.nextInt();
		int c = sc.nextInt();
		int g = sc.nextInt();
		int t = sc.nextInt();
		
		int left = 0;
		int right = P-1;
		String tmp = s.substring(0, right+1);		
		int dna[] = new int[4];	
		for (char ch : tmp.toCharArray())
		{
			if (ch=='A')
				dna[0]++;
			if (ch=='C')
				dna[1]++;
			if (ch=='G')
				dna[2]++;
			if (ch=='T')
				dna[3]++;
		}
		
		int cnt=0;
		if (dna[0] >= a && dna[1] >= c && dna[2] >= g && dna[3] >= t)
			cnt++;
		
		// left에 있는 것의 값을 제거하고 left를 이동
		// right을 이동하고 값을 갱신
		while (right+1 < s.length())
		{
			if (s.charAt(left) == 'A')
				dna[0]--;
			if (s.charAt(left) == 'C')
				dna[1]--;
			if (s.charAt(left) == 'G')
				dna[2]--;
			if (s.charAt(left) == 'T')
				dna[3]--;
			left++;
			right++;
			if (s.charAt(right) == 'A')
				dna[0]++;
			if (s.charAt(right) == 'C')
				dna[1]++;
			if (s.charAt(right) == 'G')
				dna[2]++;
			if (s.charAt(right) == 'T')
				dna[3]++;
			
			if (dna[0] >= a && dna[1] >= c && dna[2] >= g && dna[3] >= t)
			{				
				cnt++;
			}
		}
		
		System.out.println(cnt);
	}
}

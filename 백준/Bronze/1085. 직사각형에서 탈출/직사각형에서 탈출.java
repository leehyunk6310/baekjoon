import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) {
		// 상,하,좌,우 와의 거리를 체크한다.
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();
		int w = sc.nextInt();
		int h = sc.nextInt();
		
		int []d = new int[4];
		d[0] = h - y;
		d[1] = y;
		d[2] = x;
		d[3] = w - x;
		
		Arrays.sort(d);
		System.out.println(d[0]);
		
	}

}

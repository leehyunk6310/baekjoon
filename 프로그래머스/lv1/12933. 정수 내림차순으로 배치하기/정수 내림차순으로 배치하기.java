import java.util.Arrays;

class Solution {
    public long solution(long n) {
        long answer = 0;
        StringBuilder sb = new StringBuilder();
		char[] arr = Long.toString(n).toCharArray();
		Arrays.sort(arr);
				
		for (int i=arr.length-1; i>=0; i--)
		{
			sb.append(arr[i]);
		}		
		answer = (Long.parseLong(sb.toString()));
        return answer;
    }
}
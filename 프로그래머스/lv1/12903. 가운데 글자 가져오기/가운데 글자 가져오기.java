class Solution {
    public String solution(String s) {
        String answer = "";
        
        StringBuilder sb = new StringBuilder();
		int idx = s.length()/2;
		if (s.length()%2 == 0)
		{
			sb.append(s.charAt(idx-1));
			sb.append(s.charAt(idx));
		}
		else 
		{
			sb.append(s.charAt(idx));
		}
		
		answer = sb.toString();
        
        return answer;
    }
}
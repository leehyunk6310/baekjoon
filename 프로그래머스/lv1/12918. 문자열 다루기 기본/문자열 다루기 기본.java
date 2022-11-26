class Solution {
    public boolean solution(String s) {
        boolean answer = true;
        
        if (s.length() != 4 && s.length() != 6)
			answer = false;
		
		if (answer == true)
		{
			for (int i=0; i<s.length(); i++)
			{
				if (s.charAt(i)>'9' || s.charAt(i) < '0')
				{
					System.out.println(s.charAt(i));
					answer = false;
					break;
				}
			}
		}
        return answer;
    }
}
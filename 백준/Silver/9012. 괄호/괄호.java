import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		String s = br.readLine();
		int t = Integer.parseInt(s);

		while (t-- > 0) {
			Stack<Character> stk = new Stack<>();
			int flag = 0;

			String input = br.readLine();
			for (int i = 0; i < input.length(); i++) {
				char c = input.charAt(i);
				if (c == '(')
					stk.push(c);
				else {
					if (stk.empty()) {
						sb.append("NO\n");
						flag = 1;
						break;
					}
					stk.pop();
				}
			}
			if (flag == 0) {
				if (!stk.empty())
					sb.append("NO\n");
				else
					sb.append("YES\n");
			}
		}
		System.out.println(sb);
	}
}

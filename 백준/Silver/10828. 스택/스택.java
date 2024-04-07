import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {

		Stack<Integer> stk = new Stack<>();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int n = Integer.parseInt(s);
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String cmd = st.nextToken();

			if (cmd.equals("push")) {
				int num = Integer.parseInt(st.nextToken());
				stk.push(num);
			} else if (cmd.equals("pop")) {
				if (stk.empty()) {
					sb.append("-1");
				} else {
					sb.append(stk.peek());
					stk.pop();
				}
				sb.append("\n");
			} else if (cmd.equals("size")) {
				sb.append(stk.size());
				sb.append("\n");
			} else if (cmd.equals("empty")) {
				if (stk.empty())
					sb.append("1");
				else
					sb.append("0");
				sb.append("\n");
			} else if (cmd.equals("top")) {
				if (stk.empty()) {
					sb.append("-1");
				} else {
					sb.append(stk.peek());
				}
				sb.append("\n");
			}
		}
		System.out.println(sb);
	}
}

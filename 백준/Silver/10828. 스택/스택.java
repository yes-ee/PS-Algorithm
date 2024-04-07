import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {

		Stack<Integer> stk = new Stack<>();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int n = Integer.parseInt(s);

		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String cmd = st.nextToken();

			if (cmd.equals("push")) {
				int num = Integer.parseInt(st.nextToken());

				stk.push(num);
			} else if (cmd.equals("pop")) {
				StringBuilder sb = new StringBuilder();
				if (stk.empty()) {
					sb.append("-1");
				} else {
					sb.append(stk.peek());
					stk.pop();
				}
				System.out.println(sb);
			} else if (cmd.equals("size")) {
				StringBuilder sb = new StringBuilder();

				sb.append(stk.size());
				System.out.println(sb);
			} else if (cmd.equals("empty")) {
				StringBuilder sb = new StringBuilder();

				if (stk.empty())
					sb.append("1");
				else
					sb.append("0");

				System.out.println(sb);
			} else if (cmd.equals("top")) {
				StringBuilder sb = new StringBuilder();

				if (stk.empty()) {
					sb.append("-1");
				} else {
					sb.append(stk.peek());
				}

				System.out.println(sb);
			}
		}
	}
}

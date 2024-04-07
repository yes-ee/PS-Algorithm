import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());

			Deque<Integer> q = new LinkedList<>();
		while (t-- > 0) {
			String s = br.readLine();

			StringTokenizer st = new StringTokenizer(s);
			String input = st.nextToken();

			if (input.equals("push")) {
				int num = Integer.parseInt(st.nextToken());
				q.add(num);
				continue;
			} else if (input.equals("pop")) {
				if (q.isEmpty())
					sb.append("-1");
				else {
					sb.append(q.peek());
					q.remove();
				}
			} else if (input.equals("size")) {
				sb.append(q.size());
			} else if (input.equals("empty")) {
				if (q.isEmpty())
					sb.append("1");
				else
					sb.append("0");
			} else if (input.equals("front")) {
				if (q.isEmpty())
					sb.append("-1");
				else
					sb.append(q.peek());
			} else {
				if (q.isEmpty())
					sb.append("-1");
				else
					sb.append(q.peekLast());
			}
			sb.append("\n");
		}

		System.out.println(sb);
	}
}

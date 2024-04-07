import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Deque<Integer> dq = new LinkedList<>();

		int n = Integer.parseInt(br.readLine());

		while (n-- > 0) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);

			String input = st.nextToken();

			if (input.equals("push_back")) {
				int num = Integer.parseInt(st.nextToken());

				dq.addLast(num);
			} else if (input.equals("push_front")) {
				int num = Integer.parseInt(st.nextToken());

				dq.addFirst(num);
			} else if (input.equals("pop_front")) {
				if (dq.isEmpty())
					sb.append("-1");
				else {
					sb.append(dq.peekFirst());
					dq.removeFirst();
				}
				sb.append("\n");

			} else if (input.equals("pop_back")) {
				if (dq.isEmpty())
					sb.append("-1");
				else {
					sb.append(dq.peekLast());
					dq.removeLast();
				}
				sb.append("\n");
			} else if (input.equals("size")) {
				sb.append(dq.size()).append("\n");
			} else if (input.equals("empty")) {
				if (dq.isEmpty())
					sb.append("1");
				else
					sb.append("0");
				sb.append("\n");
			} else if (input.equals("front")) {
				if (dq.isEmpty())
					sb.append("-1");
				else
					sb.append(dq.peekFirst());
				sb.append("\n");
			} else {
				if (dq.isEmpty())
					sb.append("-1");
				else
					sb.append(dq.peekLast());
				sb.append("\n");
			}
		}

		System.out.println(sb);
	}
}

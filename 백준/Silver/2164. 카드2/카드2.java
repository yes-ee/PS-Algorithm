import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Queue<Integer> q = new LinkedList<>();

		int n = Integer.parseInt(br.readLine());

		for (int i = 1; i <= n; i++) {
			q.add(i);
		}

		while (q.size() != 1) {
			q.remove();
			int x = q.peek();
			q.remove();
			q.add(x);
		}

		sb.append(q.peek());

		System.out.println(sb);
	}
}

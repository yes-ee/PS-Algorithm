import java.io.*;
import java.sql.Array;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Stack<Double> st = new Stack<>();

		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];

		String input = br.readLine();

		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(br.readLine());
			arr[i] = num;
		}

		for (int i = 0; i < input.length(); i++) {
			char c = input.charAt(i);

			if (c >= 'A' && c <= 'Z') {
				double tmp = arr[c - 'A'];
				st.add(tmp);
			}
			else {
				double y = st.peek();
				st.pop();
				double x = st.peek();
				st.pop();

				if (c == '+')
					st.add(x + y);
				else if (c == '-')
					st.add(x - y);
				else if (c == '*')
					st.add(x * y);
				else
					st.add(Math.floor(x / (double) y * 100) / 100.0);
			}
		}

		double ans = st.peek();

		System.out.printf("%.2f", ans);
	}
}

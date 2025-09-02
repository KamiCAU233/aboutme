import java.util.Scanner;

public class StringEncryption {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int offset = sc.nextInt();
        char[] s = str.toCharArray();
        // Keep everything within the range of (a ~ Z)
        for (int i = 0; i < s.length; i++) {
            char ch = 'a';
            if (s[i] >= 'a' && s[i] <= 'z') {
                ch = 'a';
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                ch = 'A';
            }
            if (s[i] == ' ') {
                continue;
            } else if (s[i] - offset < ch) {
                s[i] = (char)((int)s[i] - (offset - 1) + (int)'Z' - (int)'A');
                // s[i] = (char)((int)ch + (int)'Z' - ((int)'A' + (offset - 1)));
                continue;
            }
            s[i] -= offset;
        }
        System.out.println(s);
    }
}

import java.util.Scanner;

public class LongestWord {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String[] punctuations = new String[]{",", ".", "!", "?", ":"};
        for (int i = 0; i < punctuations.length; i++) {
            str = str.replace(punctuations[i], " ");
        }
        String[] words = str.split(" ");
        int[] length = new int[words.length];
        for (int i = 0; i < words.length; i++) {
            length[i] = words[i].length();
        }
        int max_index = 0;
        int max = length[0];
        for (int i = 0; i < length.length; i++) {
            if (length[i] > max) {
                max_index = i;
                max = length[i];
            }
        }
        System.out.println(words[max_index]);
    }
}

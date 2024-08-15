import java.util.Scanner;
public class ReadingInput1 {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.println("Answer the following quiz");
        System.out.println("Giraffe is a carnivore  True/False");
        boolean ans1=s.nextBoolean();
        System.out.println("How many Sustainable Development Goals (SDG) are adopted by the United Nations?");
        int ans2 = s.nextInt();
        s = new Scanner(System.in);     //to clear the buffer so newline character is not accepted as part of string
        System.out.println("Who has been adopted as Goa's new brand ambassador to promote yoga?");
        String ans3 = s.nextLine();
        int score = 0;
        if(ans1 == false) { score++; }
        if(ans2 == 17) { score++; }
        if(ans3.equals("Namrata")) { score++; }
        System.out.println("Total Score: " + score);
    }
}

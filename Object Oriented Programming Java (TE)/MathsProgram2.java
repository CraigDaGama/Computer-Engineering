package Unit1_maths;
public class MathsProgram2 {
    public static void main(String args[]) {
        System.out.println("Roll Dice");
        for (int i = 0; i < 6; i++) {
            double dice = Math.random() * (6 - 1) + 1;
            // Math.random()*(max-min) + min ........ [min, max]
            System.out.println("Dice outcome: " + Math.round(dice));
        }
    }
}
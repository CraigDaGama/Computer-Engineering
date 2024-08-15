public class IntegerDataType {
    public static void main(String args[]) {
        byte x1 = (byte) 256;    //type cast needs to be put for type narrowing to avoid lossy conversion
        byte x2 = 0x1F;
        short x3 = 0b00_11;
        int x4 = 11_123;
        long x5 = 222224444;
        System.out.println("byte variable x1=" + x1);
        System.out.println("byte variable x2=" + x2);
        System.out.println("short variable x3=" + x3);
        System.out.println("int variable x4=" + x4);
        System.out.println("long variable x5=" + x5);
    }
}

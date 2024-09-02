import java.io.*;
public class ConcatenatingAndBufferingFiles
{
    public static void main(String args[]) throws IOException
    {
        FileInputStream file1 = new FileInputStream("data1.txt");
        FileInputStream file2 = new FileInputStream("data2.txt");
        SequenceInputStream file3 = new FileInputStream(file1, file2);
        BufferedOutputStream bout = new BufferedOutputStream(System.out);
        BufferedIntputStream bin = new BufferedIntputStream(file3);
        int ch;
        while((ch=bin.read())!=-1)
        {
            bout.write((char)ch);
        }
        bin.close();
        file1.close();
        file2.close();
    }
}

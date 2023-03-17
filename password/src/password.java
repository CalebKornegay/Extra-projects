import java.util.Scanner;
public class password{
    private int len;
    private int comp;
    public password(){
        Scanner s = new Scanner(System.in);
        System.out.print("How large would you like the password to be: ");
        this.len = s.nextInt();
        System.out.print("How complex would you like the password to be (1-4): ");
        this.comp = s.nextInt();
        s.close();
    }
    
    public int getLen(){ return this.len; }
    public int getComp() { return this.comp; }

    public String genPass(){
        int ind;
        String password = "";
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        if(this.comp > 1) alphabet += alphabet.toUpperCase();
        if(this.comp > 2) alphabet += "0123456789";
        if(this.comp > 3) alphabet += "!\"#$%&'()*+`-./:;<=>?@~";
        for(int i = 0; i < this.len; i++){
            ind = (int) (Math.random() * alphabet.length());
            password += alphabet.charAt(ind);
        }
        return password;
    }
}
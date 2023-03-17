public class main{
    public static void main(String[] args){
        password p = new password();
        System.out.format("You asked for a password with %d characters and a %d in complexity\n", p.getLen(), p.getComp());
        System.out.format("Your generated password is: %s\n", p.genPass());
    }
}
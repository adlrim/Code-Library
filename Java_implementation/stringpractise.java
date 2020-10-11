public class StringPractise{

     public static void main(String []args){
        char chars[] = {'a','b','c','d'};
        String s = new String(chars);
        System.out.println(s);
        byte ascii[] = {65,66,67,68,69,70};
        String s1 = new String(ascii);
        System.out.println(s1);
        String s2 = "abc";
        System.out.println(s2.length());
        String s3 = "He is "+9+"year old";
        System.out.println(s3);
        String s4 = "hello";
        String s5 = new String(s4);
        System.out.println(s4+"equals"+s5+"--------"+s4.equals(s5));
         System.out.println(s4+"equals"+s5+"-----------"+(s4==s5));
     }
}

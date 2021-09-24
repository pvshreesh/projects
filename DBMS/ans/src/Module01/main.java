package Module01;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

class Module1 extends JFrame
{
    static char[][] lhsarray=new char[100][100];
    static char[][] rhsarray=new char[100][100];
    static int i=0; //stores no. of FDs
    static int[] lenl= new int[100];
    static int[] lenr= new int[100];
    static int count=0;
    private static String str = ""; //stores all the keys used in the table in ascending order
    private static char[][] lhsarray2 = new char[200][100]; //stores all the lhs keys after splitting the rhs keys
    private static char[][] rhsarray2 = new char[200][100]; //stores the rhs keys after splitting
    private static int c=0;

    private static void storerel(String s1, String s2) {
        lhsarray[i] = s1.toCharArray();
        rhsarray[i] = s2.toCharArray();
        lenl[i] = s1.length();
        lenr[i] = s2.length();
        count+=lenl[i];
        //System.out.println(lenl[i]);
        //System.out.println(lenr[i]);
        i++;
        // for(int j=0;j<i;j++)
        // {
        //     System.out.println(lhsarray[j]);
        // }
    }

    private static void nextClicked(MouseEvent e, JTextField t1, JTextField t2, JTextArea a1) {
        String s1 = t1.getText();
        String s2 = t2.getText();
        t1.setText("");
        t2.setText("");
        s1 = s1.toUpperCase();
        s2 = s2.toUpperCase();
        //System.out.println(i);
        if(!s1.isEmpty()&&!s2.isEmpty())
        {
            a1.append(" "+s1+" -> "+s2+"\n");
            str = str.concat(s1+s2);
            storerel(s1, s2);
        }
        else
            System.out.println("Please input valid relations..");
    }

    private static void doneClicked(MouseEvent e, JTextArea a1) {
        a1.setText("");
        for (int j = 0; j < i; j++) {
            //System.out.println(lhsarray[j]);
            for (int k = 0; k < lenr[j]; k++) {
                lhsarray2[c] = lhsarray[j];
                rhsarray2[c][0] = rhsarray[j][k];
                for (int l = 0; l < lenl[j]; l++)
                    a1.append("" + lhsarray2[c][l]);
                a1.append(" -> " + rhsarray2[c][0] + "\n");
                c++;
            }
        }
        //a1.append(str);
        //int tablen = removeDuplicates(str);
        //System.out.println(tablen);
        //cue_brute(tablen, a1);
        solve();
        a1.append("----------------------------------------\n");
        a1.append(Decomposer.finans);
    }

    private static void refreshed(MouseEvent e, JTextArea a1) {
        a1.setText("");
        //System.out.println(lenl[0]);

        for(int j=0;j<i;j++){
            for(int k=0;k<lenl[j];k++)
            {
                lhsarray[j][k] = '0';
                //System.out.println(lhsarray[j]);
                //rhsarray[j][k] = '0';
            }
            //System.out.println(lhsarray[j]);
            //System.out.println(i);
            for(int k=0;k<lenr[i];k++)
            {
                //lhsarray[j][k] = '0';
                rhsarray[j][k] = '0';
            }
        }
        //System.out.println(lhsarray[0]);
        i = 0;
        str = "";
        count = 0;
        c = 0;
    }

    private static void cleararea(MouseEvent e, JTextArea a1) {
        a1.setText("");
    }

    public static void solve()  {
        String RAttr = ""; //String of attributes in the master relation.
        int fdNum = i;
        FuncDep[] FuncDep = new FuncDep[fdNum];
        for(int i = 0; i < FuncDep.length; i++)
        {
            // String[] in = sc.next().split("->");
            String in[]=new String[2];
            in[0]=new String(lhsarray[i]);
            in[1]=new String(rhsarray[i]);
            FuncDep[i] = new FuncDep(in[0],in[1]);
            RAttr = Decomposer.appendToStr(RAttr, in[0]);
            RAttr = Decomposer.appendToStr(RAttr, in[1]);
        }
        System.out.println("-------------------------------------------------------");

        System.out.println("Initial Relation = " + Decomposer.sortString(RAttr));


        KeyPair KR = new KeyPair(RAttr, FuncDep);
        Decomposer.finans+=("Candidate Key(s) = ");
        for(int i = 0; i < KR.cKeys.length-1; i++)
            Decomposer.finans+=(KR.cKeys[i] + ", ");
        Decomposer.finans+="\n";
        //System.out.println(KR.cKeys[KR.cKeys.length-1]);

        System.out.println("Highest NF Satisfied by Relation: " +
                Decomposer.getNFString(FuncDep, KR.cKeys));
        System.out.println("-------------------------------------------------------");

        Decomposer.printFinalAnswer(KR, FuncDep);
    }


    public static void main(String[] args){
        // creates instance of JFrame
        JFrame frame1 = new JFrame("Module I");

        // creates instance of JTextfield
        final JTextField textfield1 = new JTextField();
        final JTextField textfield2 = new JTextField();
        //final JTextField textfield3 = new JTextField();
        //final JTextField textfield4 = new JTextField();
        //final JTextField textfield5 = new JTextField();
        //final JTextField textfield6 = new JTextField();

        // creates instance of JTextArea
        JTextArea ta1 = new JTextArea();
        //JTextArea ta2 = new JTextArea();

        // creates instance of JButton
        JButton button1 = new JButton("next");
        JButton button2 = new JButton("DONE");
        JButton button3 = new JButton("refresh");
        //JButton button4 = new JButton("delete");
        JButton button5 = new JButton("CLEAR");


        // creates instance of JLabel
        JLabel l0 = new JLabel("Decomposition Of Relations");
        JLabel l1 = new JLabel(">>");
        JLabel l2 = new JLabel("Relations Input :");
        JLabel l3 = new JLabel("FDs:");
        JLabel l4 = new JLabel("LHS");
        JLabel l5 = new JLabel("RHS");
        //JLabel l6 = new JLabel("Primary Key:");
        //JLabel l7 = new JLabel("Highest NF:");
        //JLabel l8 = new JLabel("After decomposition:");
        JLabel l9 = new JLabel(">>>>>");
        Font font = new Font("Courier", Font.BOLD,16);
        l0.setFont(font);

        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
            {
                lhsarray[j][k] = '0';
                rhsarray[j][k] = '0';
                //System.out.println(lhsarray[0][0]);
            }

        // x axis, y axis, width, height
        button1.setBounds(33, 190 ,90, 20);
        button2.setBounds(33, 265, 90, 20);
        //button4.setBounds(33,155,90,20);
        button3.setBounds(33, 240, 90, 20);
        button5.setBounds(70, 380, 90, 20);
        textfield1.setBounds(5,160, 60,20);
        textfield2.setBounds(90,160, 60,20);
        //textfield3.setBounds(23,350, 80,20);
        //textfield4.setBounds(183,350, 80,20);
        //textfield5.setBounds(353,350, 120,20);
        //textfield5.setBounds(33,230, 90,20);
        l0.setBounds(150, 10, 250, 20);
        l1.setBounds(70,160, 20,20);
        l2.setBounds(34, 100, 120, 20);
        l3.setBounds(10, 120, 30, 20);
        l4.setBounds(23, 140, 30, 20);
        l5.setBounds(107, 140, 30, 20);
        //l6.setBounds(23, 320, 80, 20);
        //l7.setBounds(183, 320, 80, 20);
        //l8.setBounds(353, 320, 120, 20);
        l9.setBounds(163, 380, 50, 20);
        ta1.setBounds(205,65,300,350);
        //ta2.setBounds(333, 350, 160, 100);

        // tooltip texts
        button1.setToolTipText("Adds a new FD to the set");
        button2.setToolTipText("Evaluates the FDs for NF");
        button3.setToolTipText("Deletes all the FDs from the set");
        //button4.setToolTipText("Deletes the inputted FD from the set, if exists");
        button5.setToolTipText("Clears the text area, does not affect the relations stored");
        ta1.setEditable(false);
        //textfield3.setEditable(false);
        //textfield4.setEditable(false);
        //textfield5.setEditable(false);
        //textfield3.setText("Mister");


        // buttons' methods are shown
        button1.addMouseListener(new MouseAdapter(){
            @Override
            public void mouseClicked(MouseEvent e){
                nextClicked(e, textfield1, textfield2, ta1);
            }
        });
        button2.addMouseListener(new MouseAdapter(){
            @Override
            public void mouseClicked(MouseEvent e){
                doneClicked(e, ta1);
            }
        });
        button3.addMouseListener(new MouseAdapter(){
            @Override
            public void mouseClicked(MouseEvent e){
                refreshed(e, ta1);
            }
        });
        button5.addMouseListener(new MouseAdapter(){
            @Override
            public void mouseClicked(MouseEvent e){
                cleararea(e, ta1);
            }
        });

        // adds widgets in frame
        frame1.add(textfield1);
        frame1.add(textfield2);
        //frame1.add(textfield3);
        //frame1.add(textfield4);
        //frame1.add(textfield5);
        frame1.add(button1);
        frame1.add(button2);
        frame1.add(button3);
        //frame1.add(button4);
        frame1.add(button5);
        frame1.add(l0);
        frame1.add(l1);
        frame1.add(l2);
        frame1.add(l3);
        frame1.add(l4);
        frame1.add(l5);
        //frame1.add(l6);
        //frame1.add(l7);
        //frame1.add(l8);
        frame1.add(l9);
        frame1.add(ta1);
        //frame1.add(ta2);

        // 400 width and 500 height of frame1
        frame1.setSize(550, 500) ;

        // uses no layout managers
        frame1.setLayout(null);

        // makes the frame visible
        frame1.setVisible(true);
        //sc.close();
    }
}
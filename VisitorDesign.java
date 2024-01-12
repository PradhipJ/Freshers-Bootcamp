class WordDocument {
    DocumentPart[] documentParts;
    IConverter converter;
    WordDocument(DocumentPart[] documentParts, IConverter converter){
        this.documentParts = documentParts;
        this.converter = converter;
    }
    public boolean open(String path) {
        for(DocumentPart part: documentParts){
            part.paint();
        }
        return true;
    }
    public boolean save(String path) {
        for(DocumentPart part: documentParts){
            if(!part.save(path)){
                System.out.println("Save failed");
                return false;
            }
        }
        return true;
    }
    public void convertToHTML(){
        for(DocumentPart part: documentParts){
            part.convert(converter);
        }
    }
}

interface IConverter {
    public void convert(Header header);
    public void convert(Footer footer);
    public void convert(Paragraph paragraph);
    public void convert(Hyperlink hyperlink);
}

class HTMLConverter implements IConverter {
    public void convert(Header header){
        System.out.println("Converting header to html");
    }
    
    public void convert(Footer footer){
        System.out.println("Converting footer to html");
    }
    
    public void convert(Paragraph paragraph){
        System.out.println("Converting paragraph to html");
    }
    
    public void convert(Hyperlink hyperlink){
        System.out.println("Converting hyperlink to html");
    }
}

abstract class DocumentPart {
    String name;
    Integer[] coordinates;
    IConverter converter;
    public DocumentPart(IConverter converter){
        this.converter = converter;
    }
    abstract void paint();
    abstract boolean save(String destination);
    abstract void convert(IConverter converter);
}

class Paragraph extends DocumentPart {
    public Paragraph(){
        super(new HTMLConverter());
    }
    
    void paint(){
        System.out.println("Painting paragraph");
    }
    boolean save(String destination){
        //successful save
        if(true) {
            System.out.println("Paragraph saved to " + destination);
            return true;
        }
        //save failed
        return false;
    }
    public void convert(IConverter converter){
        converter.convert(this);
    }
}

class Hyperlink extends DocumentPart{
    public Hyperlink(){
        super(new HTMLConverter());
    }
    
    void paint(){
        System.out.println("Painting hyperlink");
    }
    boolean save(String destination){
        //successful save
        if(true) {
            System.out.println("Hyperlink saved to " + destination);
            return true;
        }
        //save failed
        return false;
    }
     public void convert(IConverter converter){
        converter.convert(this);
    }
}

class Header extends DocumentPart {
    public Header(){
        super(new HTMLConverter());
    }
    
    void paint(){
        System.out.println("Painting Header");
    }
    boolean save(String destination){
        //successful save
        if(true) {
            System.out.println("Header saved to " + destination);
            return true;
        }
        //save failed
        return false;
    }
     public void convert(IConverter converter){
        converter.convert(this);
    }
}

class Footer extends DocumentPart {
    public Footer(){
        super(new HTMLConverter());
    }
    
    void paint(){
        System.out.println("Painting Footer");
    }
    boolean save(String destination){
        //successful save
        if(true) {
            System.out.println("Footer saved to " + destination);
            return true;
        }
        //save failed
        return false;
    }
     public void convert(IConverter converter){
        converter.convert(this);
    }
}

public class VisitorDesign{
    public static void main(String args[]) {
        
        DocumentPart paragraph = new Paragraph();
        DocumentPart hyperlink = new Hyperlink();
        DocumentPart header = new Header();
        DocumentPart footer = new Footer();
    
        DocumentPart[] parts = new DocumentPart[]{paragraph, hyperlink, header, footer};
        
        WordDocument wordDoc = new WordDocument(parts, new HTMLConverter());
        
        boolean openResult = wordDoc.open("/");
        boolean saveResult = wordDoc.save("/");
        
        wordDoc.convertToHTML();
    
    }
}
package aula02;

class CellPhone {
    private String number;
    private String model;
    private Double battery;
    private Double lightness;
    
    public CellPhone(String number, String model, Double battery, Double lightness) {
        this.number = number;
        this.model = model;
        this.battery = battery;
        this.lightness = lightness;
    }

    public void lowerBattery() {
        if (this.getBattery() > 0) {
            this.setBattery(this.getBattery() - (this.getBattery() * .05));
        } else {   
            System.out.println("Não se pode reduzir uma bateria, ela já está em 0%.");
        }
    }
    
    public void upperBattery() {
        if (this.getBattery() < 100) {
            this.setBattery(this.getBattery() + (this.getBattery() * .05));
        } else {
            System.out.println("Não se pode aumentar uma bateria, ela já está em 100%.");
        }
    }

    public void lowerLightness() {
        if (this.getLightness() > 0) {
            this.setLightness(this.getLightness() - (this.getLightness() * .05));
        } else {   
            System.out.println("Não se pode reduzir a iluminação, ela já está em 0%.");
        }
    }
    
    public void upperLightness() {
        if (this.getLightness() < 100) {
            this.setLightness(this.getLightness() + (this.getLightness() * .05));
        } else {
            System.out.println("Não se pode aumentar a iluminação, ela já está em 100%.");
        }
    }



    public String getNumber() {
        return number;
    }
    public void setNumber(String number) {
        this.number = number;
    }
    public String getModel() {
        return model;
    }
    public void setModel(String model) {
        this.model = model;
    }
    public Double getBattery() {
        return battery;
    }
    public void setBattery(Double battery) {
        this.battery = battery;
    }
    public Double getLightness() {
        return lightness;
    }
    public void setLightness(Double lightness) {
        this.lightness = lightness;
    }

    
}
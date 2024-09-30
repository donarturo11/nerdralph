MCU     ?= attiny85 
SPEED   ?= 8000000L 
AVRARCH ?= avr25

CC      = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
OBJOPTS = -j .text -j .data
OPTIONS = -Os -flto -mmcu=$(MCU) -DF_CPU=$(SPEED) -ffixed-r2
OBJECTS = wgmuart.o wgmisr.o main.o
TARGET  = wgmuart

PROGRAMMER ?= usbasp -B 4

.PHONY: $(TARGET)

all: $(TARGET).hex $(TARGET).asm

$(TARGET).elf: $(OBJECTS)
	$(CC) $(OPTIONS) -o $@ $^
	avr-size $@

$(TARGET).asm: $(TARGET).hex
	$(OBJDUMP) --no-show-raw-insn -m$(AVRARCH) -D -S $(TARGET).elf > $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) $(OBJOPTS) -O ihex $< $@

%.o: %.[c,S]
	$(CC) $(OPTIONS) -c -o $@ $<


flash:  $(TARGET)
	avrdude -C /etc/avrdude.conf -p $(DEVICE) -c $(PROGRAMMER) -U flash:w:$(TARGET):e

clean:
	$(RM) *.o *.elf *.hex *.asm *.bin

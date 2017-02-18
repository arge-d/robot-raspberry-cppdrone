CPP 	=	g++
OUTDIR 	= build
OUTNAME	= cppdrone

SRC 	= 	main.cpp \
			src/mpu9255.cpp \
			src/pca9685.cpp \
			src/pid.cpp \
			src/i2c.cpp

INC 	=	include/


$(OUTDIR)/$(OUTNAME): $(SRC)
	@mkdir -p $(OUTDIR)
	@g++ -I$(INC) $(SRC) -o $@
	@echo "Compiled..."

clean: $(OUTDIR)
	@rm -rf $(OUTDIR)

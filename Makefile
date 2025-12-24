SCENE:=box cloud sphere tetrahedron octa icosa

PROJ:=up dn lf rt ft bk spherical

PNGS:=$(foreach S, ${SCENE}, ${foreach P, ${PROJ}, ${S}_${P}.png } )

INCS:=$(foreach S, ${SCENE}, ${S}.inc )

all: .depends ${PNGS}

.PHONY: all clean

# don't delete intermediate files:
.SECONDARY:

.ONESHELL:

# Y dimension of the generated images:
HEIGHT=512

# High quality mode:
POV_OPT=+d +v -p +a0.1 +am2 +r3

# Fast mode:
#POV_OPT=+d +v -p -a

.depends: makedepends.sh skybox.pov ${INCS}
	./makedepends.sh ${PNGS}

-include .depends

%.png : skybox.pov
	echo SCENE: ${SCENE}
	echo PNGS: ${PNGS}
	SC=`echo $@ | sed 's/\([a-z0-9]*\)_.*/\1/g'`
	CAMERA=`echo $@ | sed 's/[a-z0-9]*_\([a-z]*\).*/\1/g'`
	echo == Sc= $$SC == Camera= $$CAMERA ==
	
	rm -fv scene.inc
	ln -v $$SC.inc scene.inc
	
	WIDTH=` if [ $$CAMERA = "spherical" ] ; then echo  ${HEIGHT} \* 2 | bc ; else echo ${HEIGHT}; fi`
	echo == Width= $$WIDTH == Height= $(HEIGHT) ==
	
	echo '#declare CAMERA="'$$CAMERA'"' > defs.inc
	echo '#declare ROT=<22,22,22>;' >> defs.inc
	
	povray ${POV_OPT} -h${HEIGHT} -w$$WIDTH -o$@ -iskybox.pov


tetra.png : skybox.pov tetrahedron.inc triangle.inc
	rm -fv scene.inc
	ln -v tetrahedron.inc scene.inc
	echo '#declare CAMERA="normal"' > defs.inc
	povray ${POV_OPT} -o$@ -iskybox.pov +w4096 -h4096


clean:
	rm -vf ${PNGS}
	rm -vf .depends scene.inc defs.inc

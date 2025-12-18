all: box_up.png box_dn.png box_lf.png box_rt.png box_ft.png box_bk.png box_spherical.png \
     ubox_up.png ubox_dn.png ubox_lf.png ubox_rt.png ubox_ft.png ubox_bk.png ubox_spherical.png \
     tetrahedron_up.png tetrahedron_dn.png tetrahedron_lf.png tetrahedron_rt.png tetrahedron_ft.png tetrahedron_bk.png tetrahedron_spherical.png \
     sphere_up.png sphere_dn.png sphere_lf.png sphere_rt.png sphere_ft.png sphere_bk.png sphere_spherical.png

.PHONY: all clean

# don't delete intermediate files:
.SECONDARY:

# High quality mode:
POV_OPT=-d +v -p +a0.1 +am2 +r3 -w1024 -h1024

# Fast mode:
#POV_OPT=+d +v -p -a  -w512 -h512

box_spherical.png : skybox.pov box.inc
	rm -fv scene.inc
	ln -v box.inc scene.inc
	echo '#declare CAMERA="'${subst .png,,$(subst box_,,$@)}'"' > defs.inc
	povray ${POV_OPT} -w2048 -o$@ -iskybox.pov

box_%.png : skybox.pov box.inc
	rm -fv scene.inc
	ln -v box.inc scene.inc
	echo '#declare CAMERA="'${subst .png,,$(subst box_,,$@)}'"' > defs.inc
	povray ${POV_OPT} -o$@ -iskybox.pov


ubox_spherical.png : skybox.pov box.inc
	rm -fv scene.inc
	ln -v box.inc scene.inc
	echo '#declare CAMERA="'${subst .png,,$(subst ubox_,,$@)}'"' > defs.inc
	echo '#declare ROT=<0, 45, 54.735610317245345685>;' >> defs.inc
	povray ${POV_OPT} -w2048 -o$@ -iskybox.pov

ubox_%.png : skybox.pov box.inc
	rm -fv scene.inc
	ln -v box.inc scene.inc
	echo '#declare CAMERA="'${subst .png,,$(subst ubox_,,$@)}'"' > defs.inc
	echo '#declare ROT=<0, 45, 54.735610317245345685>;' >> defs.inc
	povray ${POV_OPT} -o$@ -iskybox.pov


tetrahedron_spherical.png : skybox.pov tetrahedron.inc triangle.inc
	rm -fv scene.inc
	ln -v tetrahedron.inc scene.inc
	echo '#declare CAMERA="'${subst .png,,$(subst tetrahedron_,,$@)}'"' > defs.inc
	povray ${POV_OPT} -w2048 -o$@ -iskybox.pov

tetrahedron_%.png : skybox.pov tetrahedron.inc triangle.inc
	rm -fv scene.inc
	ln -v tetrahedron.inc scene.inc
	echo '#declare CAMERA="'${subst .png,,$(subst tetrahedron_,,$@)}'"' > defs.inc
	povray ${POV_OPT} -o$@ -iskybox.pov

tetra.png : skybox.pov tetrahedron.inc triangle.inc
	rm -fv scene.inc
	ln -v tetrahedron.inc scene.inc
	echo '#declare CAMERA="normal"' > defs.inc
	povray ${POV_OPT} -o$@ -iskybox.pov +d +c


sphere_spherical.png : skybox.pov sphere.inc
	rm -fv scene.inc
	ln -v sphere.inc scene.inc
	echo '#declare CAMERA="'${subst .png,,$(subst sphere_,,$@)}'"' > defs.inc
	povray ${POV_OPT} -w2048 -o$@ -iskybox.pov

sphere_%.png : skybox.pov sphere.inc
	rm -fv scene.inc
	ln -v sphere.inc scene.inc
	echo '#declare CAMERA="'${subst .png,,$(subst sphere_,,$@)}'"' > defs.inc
	povray ${POV_OPT} -o$@ -iskybox.pov

clean:
	rm -vf box_*.png sphere_*.png ubox_*.png tetrahedron_*.png

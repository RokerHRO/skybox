# Skybox – use POV-Ray to generate skyboxes for Cube2/Sauerbraten game scenes

## How to use

Just type `make` and the example images below will be generated. For Cube2/Sauerbraten you only need the images with `_ft`, `_bk`, `_lf`, `_rt`, `_up` and `_dn` in their names for the "front", "back", "left", "right", "up" and "down" side of your skybox. This naming scheme is mandatory for the game engine to find the 6 images!

Put the generated images in your textures directory, I've a special `textures/sky` subdirectory and refer to the desired skybox in the scene's `.cfg` file:

```cpp
// loadsky textures/sky/box
// loadsky textures/sky/sphere
loadsky textures/sky/ubox
```

# Examples
## A grid box as skyboximplest case: A square grid on each of the six faces of the skybox:

<img src="https://github.com/user-attachments/assets/13df3c42-5ca4-4fd4-a2f2-578742e13114" width="256" />
<img src="https://github.com/user-attachments/assets/212028b3-fb2d-4785-8f94-64f2386a9fb7" width="256" />
<img src="https://github.com/user-attachments/assets/149c5db2-47f3-4524-b658-c166c896ad1f" width="256" />
<img src="https://github.com/user-attachments/assets/0d6f3413-992d-464f-93db-19a17b9e9d9e" width="256" />
<img src="https://github.com/user-attachments/assets/22f33abe-7f7f-4a0b-af62-a3381839788c" width="256" />
<img src="https://github.com/user-attachments/assets/8af282ff-dc2b-4c39-b6b0-dfe7a6600df4" width="256" />

As a "spherical mapping" (plate carrée projection) this map looks like this:
![box_spherical](https://github.com/user-attachments/assets/fa1c0392-39cb-465c-b794-bf74cb2ae0aa)


### A rotated box as skybox
If the box is rotated that it stands on one of its corners: The white sphere is in the zenith above your head, the dark sphere in the nadir below your feet. The six skybox faces look like these:

<img src="https://github.com/user-attachments/assets/50d3dd0c-b037-415f-b223-912396e88909" width="256" />
<img src="https://github.com/user-attachments/assets/b6963733-d952-41d8-acdb-57e4182e63db" width="256" />
<img src="https://github.com/user-attachments/assets/f236cfb2-f7e1-4e2d-a10a-14b3e6ca113e" width="256" />
<img src="https://github.com/user-attachments/assets/5b09113c-10fa-496e-8ea8-55d5b525d47b" width="256" />
<img src="https://github.com/user-attachments/assets/8cd2e502-f6ee-46f4-b687-5bf37d94bafa" width="256" />
<img src="https://github.com/user-attachments/assets/e9059bf9-d85c-4315-9cc8-9d340e781f98" width="256" />

And the plate carrée looks quite funny:
![ubox_spherical](https://github.com/user-attachments/assets/44b027da-0616-4472-90ef-6d7b223873c8)

### A grid globe as skybox
If you use a grid globe you'll not notice that the sky is created from 6 square faces:

<img src="https://github.com/user-attachments/assets/4104c19a-869a-4b7e-b7f1-607484bba20b" width="256" />
<img src="https://github.com/user-attachments/assets/71eb6cfa-197b-49a6-ad63-c3c2df0d8f05" width="256" />
<img src="https://github.com/user-attachments/assets/ddd7f246-27b7-4c1a-b7bf-fcaa5d263558" width="256" />
<img src="https://github.com/user-attachments/assets/b3b4df58-d325-4e38-a804-3fba2c50159b" width="256" />
<img src="https://github.com/user-attachments/assets/014270a8-ee3d-4af4-817c-32351583b569" width="256" />
<img src="https://github.com/user-attachments/assets/3d63f0ad-6d65-4dbd-bd51-ff5397e535fd" width="256" />

The plate carrée of this skybox is not really surprising:
![sphere_spherical](https://github.com/user-attachments/assets/45b7fb85-c0be-477e-bcd0-1928a01f3cb3)

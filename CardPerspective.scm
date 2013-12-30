; To be placed in ~/.gimp2.x/scripts (or equivalent)

(define (CardPerspective Filename)

(define img (car (gimp-file-load 1 Filename Filename)))
(define drawable (car (gimp-image-active-drawable img)))
(define result (car(gimp-drawable-transform-matrix-default drawable
		0.55932 -0.15625 25
		0.00000 0.24057 51
		0.00000 -0.00275 1
		1 0)))
(gimp-file-save RUN-NONINTERACTIVE img result Filename Filename)
(gimp-image-delete img)
)

(define (CardResize Filename)

(define img (car (gimp-file-load 1 Filename Filename)))
(define drawable (car (gimp-image-active-drawable img)))
(define result (car (gimp-image-scale-full img 60 60 INTERPOLATION-CUBIC)))
(gimp-file-save RUN-NONINTERACTIVE img drawable Filename Filename)
(gimp-image-delete img)
)


<!--
	$FreeBSD$
	$FreeBSDde: de-docproj/relnotes/de_DE.ISO8859-1/share/sgml/release.dsl,v 1.8 2002/10/13 16:40:33 ue Exp $
	basiert auf: 1.6.2.1
-->

<!DOCTYPE style-sheet PUBLIC "-//James Clark//DTD DSSSL Style Sheet//EN" [
<!ENTITY release.dsl PUBLIC "-//FreeBSD//DOCUMENT Release Notes DocBook Language Neutral Stylesheet//EN" CDATA DSSSL>
<!ENTITY % output.html  "IGNORE"> 
<!ENTITY % output.print "IGNORE">
]>

<style-sheet>
  <style-specification use="docbook">
    <style-specification-body>
 
      <![ %output.html; [ 
	(define ($email-footer$)
          (make sequence
	    (make element gi: "p"
                  attributes: (list (list "align" "center"))
              (make element gi: "small"
                (literal "Diese Datei und andere Dokumente zu dieser Version sind bei ")
		(create-link (list (list "HREF" (entity-text "release.url")))
                  (literal (entity-text "release.url")))
                (literal "verfuegbar.")))
            (make element gi: "p"
                  attributes: (list (list "align" "center"))
              (make element gi: "small"  
                (literal "Wenn Sie Fragen zu FreeBSD haben, lesen Sie erst die ")
		(create-link
		  (list (list "HREF" "http://www.FreeBSD.org/docs.html"))
                  (literal "Dokumentation,"))
                (literal " bevor Sie sich an <")
		(create-link
		  (list (list "HREF" "mailto:de-bsd-questions@de.FreeBSD.org"))
                  (literal "de-bsd-questions@de.FreeBSD.org"))
                (literal "> wenden.")
            (make element gi: "p"
                  attributes: (list (list "align" "center"))
	      (literal "Wenn Sie Fragen zu dieser Dokumentation haben, wenden Sie sich an <")
	      (create-link (list (list "HREF" "mailto:de-bsd-translators@de.FreeBSD.org"))
                (literal "de-bsd-translators@de.FreeBSD.org"))
	      (literal ">."))))))

	<!-- Convert " ... " to `` ... '' in the HTML output. -->
	(element quote
	  (make sequence
	    (literal "``")
	    (process-children)
	    (literal "''")))

        <!-- Generate links to HTML man pages -->
        (define %refentry-xref-link% #t)

        <!-- Specify how to generate the man page link HREF -->
        (define ($create-refentry-xref-link$ #!optional (n (current-node)))
          (let* ((r (select-elements (children n) (normalize "refentrytitle")))
                 (m (select-elements (children n) (normalize "manvolnum")))
                 (v (attribute-string (normalize "vendor") n))
                 (u (string-append "http://www.FreeBSD.org/cgi/man.cgi?query="
                         (data r) "&" "sektion=" (data m))))
            (case v
              (("xfree86") (string-append u "&" "manpath=XFree86+4.2.0"))
              (("netbsd")  (string-append u "&" "manpath=NetBSD+1.5"))
              (("ports")   (string-append u "&" "manpath=FreeBSD+Ports"))
              (else        (string-append u "&" "manpath=FreeBSD+5.0-RELEASE")))))
      ]]>

      (define (toc-depth nd)
        (if (string=? (gi nd) (normalize "book"))
            3
            3))

    </style-specification-body>
  </style-specification>

  <external-specification id="docbook" document="release.dsl">
</style-sheet>

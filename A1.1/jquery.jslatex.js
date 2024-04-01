/*
 * jsLaTeX v1.2.2 - A jQuery plugin to directly embed LaTeX into your website or blog
 * 
 *  Copyright (c) 2009 Andreas Grech
 *
 *  Licensed under the WTFPL license:
 *    http://www.wtfpl.net/about/
 *
 * http://dreasgrech.com
 */

(function ($) { /* a self-executing anonymous function and passes jQuery as a parameter to locally reference jQuery as $ inside the function scope */
    /* Defines a function attachToImage that creates an img element with the src attribute set to the value of this.src */
    var attachToImage = function () {
        return $("<img/>").attr({
            src: this.src
        });
    },
    /* formats: Creates an object formats that maps different output formats ('gif','png','swf') to corresponding formatting functions */
        formats = {
        'gif': attachToImage,
        'png': attachToImage,
        'swf': function () {
            return $("<embed/>").attr({
                src: this.src,
                type: 'application/x-shockwave-flash'
            });
        }
    },
    /* sections: Defines an object that maps placeholders like '{f}' and '{e}' to their corresponding properties in the options object */
        sections = {
        '{f}': 'format',
        '{e}': 'equation'
    },
    /* escapes: Creates an object that provides mappings for special characters like '+' & '=' for URL encoding. */
        escapes = {
        '+': '2B',
        '=': '3D'
    };
    
    $.fn.latex = function (opts) { /* Extends jQuery by adding a new method latex to process LaTeX equations based on the provided options */
        opts = $.extend({},        /* Merges default options ($.fn.latex.defaults) with the user-provided options using jQuery's $.extend() method. */
        $.fn.latex.defaults, opts); 
        opts.format = formats[opts.format] ? opts.format : 'gif'; /* Checks if the specified format in options is valid; if not, defaults to 'gif' */
        return this.each(function () { /* Iterates over each element in the jQuery object */
            var $this = $(this),
                format, s, element, url = opts.url; /* Initializes variables for the current element, format, loop index, output element, and the URL for rendering. */
            opts.equation = $.trim($this.text());   /* Trims the text content of the current element and sets it as the equation in the options. */
            
            /* Loop through sections object and replace placeholders in the URL with their corresponding option values. */
            for (s in sections) {
                if (sections.hasOwnProperty(s) && (format = url.indexOf(s)) >= 0) {
                    url = url.replace(s, opts[sections[s]]);
                }
            }

            /* Loop through escapes object and replace special characters in the URL with their encoded equivalents */
            for (s in escapes) {
                if (escapes.hasOwnProperty(s) && (format = url.indexOf(s)) >= 0) {
                    url = url.replace(s, '%' + escapes[s]);
                }
            }

            opts.src = url;  /* Sets the final URL with all replacements as the src property in the options */
            element = formats[opts.format].call(opts);  /* Calls the formatting function based on the specified format to render the LaTeX equation and stores the result in element. */
            $this.html('').append(element);             /* Clears the HTML content of the current element and appends the rendered LaTeX equation element to it. */
            
            /* If a callback function is provided in the options, it is called with the rendered element. */
            if (opts.callback) {
                opts.callback.call(element);
            }
        });
    };

    /* Sets default options for the latex function, including the default format and URL template for rendering LaTeX equations. */
    $.fn.latex.defaults = {
        format: 'gif',
        url: 'http://latex.codecogs.com/{f}.latex?{e}'
    };
    
    /* Ends the self-executing function and passes jQuery to the function to ensure the correct reference to jQuery as $ */
}(jQuery));
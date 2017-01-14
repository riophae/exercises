(function (view) {
  'use strict'

  view.$ = document.querySelector.bind(document)
  view.$$ = document.querySelectorAll.bind(document)
  view.$new = document.createElement.bind(document)

  view.ready = function (callback) {
    if (document.readyState === 'interactive' || document.readyState === 'complete') {
      callback()
    } else {
      document.addEventListener('DOMContentLoaded', () => callback(), false)
    }
  }
}(window))

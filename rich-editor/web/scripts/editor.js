/* eslint-disable */

(function (view) {
  'use strict'

  const commands = [{
    text: 'Undo',
    handler({ execCommand }) {
      execCommand('undo')
    },
  }, {
    text: 'Redo',
    handler({ execCommand }) {
      execCommand('redo')
    },
  }, {
    text: 'Copy',
    handler({ execCommand }) {
      execCommand('copy')
    },
  }, {
    text: 'Bold',
    handler({ execCommand }) {
      execCommand('bold')
    },
  }, {
    text: 'Italic',
    handler({ execCommand }) {
      execCommand('italic')
    },
  }]

  const ls_key = '__richeditor-contents__'

  class RichEditor {
    constructor(elem) {
      this.$container = elem
      this.$toolbar = this.renderToolbar()
      this.$contents = this.renderContents()

      Object.assign(this.$container, {
        className: 'richeditor',
      })
    }

    renderToolbar() {
      const $toolbar = $new('div')

      Object.assign($toolbar, {
        className: 'richeditor-toolbar',
      })

      const $buttons = $new('ul')
      $buttons.className = 'richeditor-buttons'
      commands.forEach((command) => {
        const $button = $new('li')
        $button.className = 'richeditor-button'
        $button.textContent = command.text
        $button.addEventListener('click', () => {
          command.handler({
            execCommand: this.$contents.contentDocument.execCommand.bind(this.$contents.contentDocument),
          })
        })
        $buttons.appendChild($button)
      })
      $toolbar.appendChild($buttons)

      this.$container.appendChild($toolbar)
      return $toolbar
    }

    renderContents() {
      const $contents = $new('iframe')

      Object.assign($contents, {
        className: 'richeditor-contents',
        src: 'editor-contents.htm',
      })

      $contents.addEventListener('load', () => {
        const lastData = localStorage.getItem(ls_key)
        $contents.contentDocument.body.innerHTML = lastData ||
          '<div>This text can be <strong>edited</strong>.</div>'
        $contents.contentDocument.addEventListener('input', () => {
          localStorage.setItem(ls_key, $contents.contentDocument.body.innerHTML)
        })
      }, false)

      this.$container.appendChild($contents)
      return $contents
    }
  }

  view.RichEditor = RichEditor
}(window))

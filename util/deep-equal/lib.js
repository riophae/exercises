/* eslint-disable no-use-before-define */

const objToStr = Object.prototype.toString
const arrEvery = Array.prototype.every

function getTypeTag(thing) {
  return objToStr.call(thing).slice(8, -1)
}

function isArrayLike(thing) {
  return (
    thing &&
    typeof thing === 'object' &&
    typeof thing.length === 'number' &&
    thing.length >= 0
  )
}

function compareArr(arrX, arrY) {
  if (arrX.length !== arrY.length) return false
  return arrEvery.call(arrX, (_, idx) => deepEqual(arrX[idx], arrY[idx]))
}

function hasOwn(obj, key) {
  return Object.prototype.hasOwnProperty.call(obj, key)
}

const deepEqual = module.exports = function deepEqual(value, other) { // eslint-disable-line no-multi-assign
  if (value === other) return true
  if (value == null || other == null) return value == other // eslint-disable-line eqeqeq

  const valueTypeTag = getTypeTag(value)
  const otherTypeTag = getTypeTag(other)
  if (valueTypeTag !== otherTypeTag) return false

  if (valueTypeTag === 'Number') {
    if (Number.isNaN(value)) return Number.isNaN(other)
    return Number(value) === Number(other)
  } else if (valueTypeTag === 'String') {
    return String(value) === String(other)
  } else if (valueTypeTag === 'Boolean') {
    return Boolean(value) === Boolean(other)
  } else if (valueTypeTag === 'Date') {
    return Date(value) === Date(other)
  } else if (valueTypeTag === 'Function') {
    return false
  } else if (valueTypeTag === 'RegExp') {
    return String(value) === String(other)
  } else if (valueTypeTag === 'Array') {
    return compareArr(value, other)
  } else if (isArrayLike(value)) {
    if (!isArrayLike(other)) return false
    return compareArr(value, other)
  } else if (valueTypeTag === 'Object') {
    const valueKeys = Object.keys(value)
    const otherKeys = Object.keys(other)
    if (valueKeys.length !== otherKeys.length) return false
    return valueKeys.every(key => (
      hasOwn(other, key) &&
      deepEqual(value[key], other[key])
    ))
  }

  return false
}

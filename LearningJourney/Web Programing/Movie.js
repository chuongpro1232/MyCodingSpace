
const mongoose = require('mongoose');

const MovieSchema = new mongoose.Schema({
  title: { type: String, required: true, minlength: 3, maxlength: 50 },
  releaseYear: { type: Number, required: true, min: 1900, max: new Date().getFullYear() },
  genre: { type: String, required: true },
});

module.exports = mongoose.model('Movie', MovieSchema);
            